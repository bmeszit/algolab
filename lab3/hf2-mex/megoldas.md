# MEX (már megint)

Ötlet: Használjuk a tanult unió-holvan adatszerkezetet!

## Amortizált elemzés

Először beszéljünk egy kicsit az amortizált elemzésről, mert az unió-holvan adatszerkezetben
bizonyos esetekben a lépésszámok amortizáltan vannak megadva.

Amortizált időelemzésnél nem azt nézzük, hogy egyetlen elvégzett művelet, a többitől
teljesen függetlenül mennyi ideig fog tartani, hanem azt, hogy az összes, a kezdettől
eddig a pillanatig végrehajtott műveletnek mennyi az átlagos, egy műveletre eső költsége.
Ebből következik, hogy bár időnként előfordulhatnak "drágább" műveletek, de ezek csak úgy
tudnak előjönni, ha előtte sok "olcsó" művelet történt, így hosszú távon az egy műveletre
jutó költség átlagosan mindig az adott felső korlát alá esik. Fontos még azt hangsúlyozni,
hogy itt nem valószínűségi várható értékről van szó, hanem garantált, determinisztikus
átlagról a műveletsorozatra.

Az unió-holvan adatszerkezet esetében a műveletek költségei közül igazából a `holvan`
az érdekes, mivel az `unió` két `holvan`-t és még egy kis konstans mennyiségű extra
lépést tartalmaz. Ennek a lépésszámai pedig a következőképpen alakulnak:

- Ha se a "path compression" se a "union by size" trükköt nem használjuk, akkor $O(n)$-es
lesz a futásidő, hiszen legrosszabb esetben elfajulhat láncolt listává az adatszerkezet.
- Ha csak a "union by size" trükköt alkalmazzuk, akkor még nincs szükség amortizált elemzésre,
$O(\log n)$-es lesz a futásidő, hiszen ilyenkor legrosszabb esetben is egy kiegyensúlyozott bináris
fa lesz az adatszerkezetünk.
- Ha csak a "path compression" trükköt alkalmazzuk, akkor már amortizált $O(\log n)$-ről beszélhetünk.
- Ha pedig mindkét trükköt alkalmazzuk, akkor amortizáltan "szinte konstans" (inverz Ackermann),
nem amortizáltan viszont továbbra is $O(\log n)$ lesz a futásidő, mivel a "path compression" hatását
csak amortizáltan tudjuk kihasználni az elemzéskor.

Ezért ha meg akarom engedni, hogy amortizáltan gyors adatstruktúrát használjatok,
a feladatkiírásban szereplő kérdésenkénti 1 másodperces korlátot úgy lehetett volna
precízen megfogalmazni, hogy ha sokszor gyorsan válaszolunk, akkor Tamás hajlandó néha
többet várni, vagyis a türelmi idő akkumulálódik. Én úgy láttam, hogy nagyon sokan
közületek ezt észrevettétek, és olyan megoldások jöttek, amik még ezt is figyelembe veszik,
de aki nem ilyet, viszont egyébként helyes választ adott, azokat is teljes mértékben elfogadtam. :)

## Megoldások

Mivel nagyon sok szuper megoldást kaptam, amik működnek a tényleges feladatkiírásra is, úgy gondoltam
ezek közül is hozok párat.

### Eredeti megoldás, path compression trükkel

Tudjuk, hogy $q=10^9$ darab kérdést fogunk kapni, tehát minden $q$-nál nagyobb mondott szám
ignorálható, hiszen egy $q$ méretű halmaz mex-e legfeljebb $q$. Mivel egy `int`-ben tárolható
maximális érték $2^31-1 \approx 2 \cdot 10^9$, ezért ez megfelelő lesz az értékek tárolására.
$10^9$ darab `int` körülbelül 4 GB memóriát igényel, ennek kis konstansszorosa még egy jobb
laptopon is elfér.

Tároljuk most a szülőket sima tömb helyett egy `map<int, int> p`-ben (azaz piros-fekete fában)
és legyen ez a `map` úgy specializálva, hogy ha az adott `x` elem, amit épp keresek benne
még nem létezik, akkor létrehozza azt `p[x]=x`-el!

Kezdetben legyen üres a `p`!

Ha Tamás az $i$. lépésben az `x` számot mondja, akkor Misi a következőképpen jár el:

- Ha `p[x] == x`, akkor legyen `p[x] = x+1`. (Egyébként `x` már volt korábban.)
- Misi a `holvan(0)` által visszaadott értéket válaszolja Tamásnak.

Gondoljuk végig mi történik az adatszerkezetben az algoritmus futása során: ha
Tamás még nem mondott semmit, akkor a `holvan(0)` a $0$ értéket fogja visszaadni,
ami helyes. Tegyük fel, hogy Tamás elsőre kimondja a $0$ számot: ekkor Misi feljegyzi,
hogy `p[0]=1`, aminek jelentése, hogy a $0$ helyett mostmár az $1$-et kell majd a
`holvan(0)`-nak visszaadnia, hiszen a $0$-t már elhasználtuk. Amikor Tamás egy
tetszőleges `x` értéket kimond, akkor Misi mindig a rákövetkező elemet jegyzi fel
magának, amihez a következő jelentést társíthatjuk:

"Mostmár ha `x`-et akarnék mondani, akkor helyette inkább az `x+1`-et kell mondanom!"

Tehát ilyen típusú állítások láncolatát tartalmazza az adatszerkezetünk, a szülő-gyerek
láncon keresztül az `x` érték főnöke pont az a legkisebb elem lesz, akit `x` helyett
mondania kell majd Misinek.

Tehát az algoritmus helyes.

Az adatstruktúrában $O(q)$ darab érték lesz jelen $q$ kérdés után, ezért maga
az adatstruktúra egy amortizált $O(\log q)$-s szorzóval járul hozzá a lekérdezéshez,
összességében pedig a piros-fekete fa miatt amortizált $O((\log q)^2)$ lesz a válaszidőnk.

### Union by size trükkel

(A. Ákos és Balázs megoldásai alapján)

Hasonlóan unió-holvan adatszerkezettel oldjuk meg. Használjunk egy `q+1` méretű
`vector<int>`-et tárolóként, inicializáljuk is rögtön a növekvő számsorozattal
(kezdetben mindenki saját maga főnöke). Ez az én laptopomon például ekkora
méretben kb. $8$ másodpercig fut. Ezt előkészítő lépésként megengedjük Misinek.

Használjuk most a union by size trükköt is és uniózzunk ugyanazon szabály szerint.

Misi válasza most a $0$ elemhez tartozó halmaz **mérete** lesz, amit a `holvan(0)` által
visszaadott elemhez a union by size trükk miatt egyébként is nyilvántartunk. Speciális
eset, hogyha a $0$-át még nem mondtuk, hiszen akkor is $1$ méretű a hozzá tartozó halmaz,
de ezt egyetlen `bool` flaggel kezeljük.

Látható, hogy az eredetihez hasonló érveléssel ez az algoritmus is helyes,
továbbá nem amortizáltan $O(\log q)$-s válaszidőt eredményez.

Megjegyzés: Az, hogy a `legnagyobb elem+1` a $0$-át tartalmazó halmaz esetében éppen
a méretével egyezik, egy nagyon speciális eset, az uniózási szabályunk miatt alakult így
és a többi halmazra már nem is működik.

Látható azonban, hogy a méret karbantartásához hasonló stratégiával igazából bármilyen
extra információt karbantarthatunk a halmazokról, amíg az unió műveletre értelmesen (konstans
időben) lehet számolni az új értéket: például a halmazban lévő számok maximumát, összegét,
legnagyobb közös osztóját, stb. Ha pedig nem használunk path compression trükköt,
akkor nem csak a főnökre, hanem mindenki másra is érvényes lesz a bennük tárolt érték,
a saját "részhalmazukra".

Érdekesség, hogy ha ezt a gondolatot kicsit továbbvisszük, a
[szegmensfa](https://cp-algorithms.com/data_structures/segment_tree.html)
adatszerkezetet kapjuk, ami már tetszőleges intervallumok queryzését is lehetővé teszi.

### Felokosított piros-fekete fával

(Beni megoldása alapján)

Tegyük fel, hogy már egy ideje megy a játék és az aktuális körben Misinek valahogyan
a rendelkezésére áll egy tömb, amiben rendezetten tárolja a Tamás által eddig
mondott számokat. Ha Misinek most ezt a tömböt használva kellene megmondania,
hogy mi lesz a mex, akkor a következőképpen érvelhet: a tömb elején egy darabig
a számok megegyeznek a hozzájuk tartozó cellák indexeivel, majd lesz egy pont
ahol "lyuk" van és onnantól kezdve már szigorúan nagyobb lesz az adat a saját
indexéhez képest az összes többi hátralévő elemre. Mi ennek a lyuknak az indexét
keressük, hiszen ez éppen a mex lesz, ezt pedig megtehetjük bináris kereséssel.

Igen ám, de egy ilyen tömböt Misi nem fog tudni karbantartani a kérdések során:
ha ténylegesen rendezett tömböt akar tárolni, akkor a beszúrás lesz $O(n)$-es,
ha pedig gyorsan szeretne beszúrni, akkor például láncolt listaként tárolhatja,
de abban már csak lineárisan lehet keresni, $O(n)$-ben, ami a beszúráshoz és
a válaszadáshoz is kell.

Egy trükkös adatszerkezettel azonban kiküszöbölhetjük ezt a dilemmát:

Tároljuk a Tamás által mondott értékeket egy piros-fekete fa adatszerkezetben,
azzal a megkötéssel, hogy most minden csúcs tárolja az alatta lévő részfa méretét
is. Végig lehet gondolni, hogy a beszúrás/törlés műveletek közben hogyan kell ezeket
az informáicókat frissíteni: a forgatásoknál, amikor részfák mennek át másik szülő
alá egyszerűen le kell követni a méretek változását is.

Ez a felokosított piros-fekete fa két új műveletet is támogat:

- Adott indexű elem lekérdezése $O(\log n)$-ben: Keresés közben először a bal oldali
részfa méretét nézzük meg, ha ennél kisebb a keresett elem indexe akkor balra megyünk tovább,
ellenkező esetben pedig kivonjuk ezt a méretet a keresett indexből és jobbra megyünk tovább.

- Adott elem indexének a lekérdezése $O(\log n)$-ben: Ugyanúgy keresünk benne, mint a
hagyományos piros-fekete fában, azonban menet közben, ha jobbra akarunk lépni, mindig
megnézzük először a bal oldali szomszéd részfájának a méretét és ezeknek az összegét
menet közben nyilvántartjuk. Amikor megkérkeztünk a keresett elemhez, az indexe
éppen ez a számontartott összeg lesz.

Ezt az adatszerkezetet
[Order statistic tree](https://en.wikipedia.org/wiki/Order_statistic_tree)-nek
hívják, az index alapján történő keresés a `select`, az index lekérdezése pedig a
`rank` művelet.

Ha egy ilyen adatszerkezetünk van, akkor látható, hogy a "legkisebb index, ami
szigorúan kisebb mint a hozzá tartozó adat" lekérdezése is megoldható a fenti
műveletek kis módosításával, szintén $O(\log n)$-ben.

További érdekesség, hogy `GNU gcc`-ben ilyen adatstruktúrát lehet policy based
data structure segítségével nagyon könnyen definiálni, lásd: https://codeforces.com/blog/entry/11080 .
