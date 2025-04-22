# Bitjáték

Vegyük a következő gráfot: a csúcsai a lehetséges bitsorozatok (a tiltott sorozatokat fel sem vesszük), $s$ a kezdőcsúcs, irányítatlan él pedig akkor köt össze két csúcsot, ha a bitsorozatok pontosan egy pozícióban térnek el, azaz egyikből át lehet lépni a másikba.

Figyelem: Ez a gráf nem nevezhető a játék állapotgráfjának, mert nem írja le azt a feltételt, hogy nem léphetünk vissza már meglátogatott csúcsba. A játék állapotgráfja egy ennél sokkal nagyobb gráf, amely az adott csúcsban tartalmazza azt az extra információt is, hogy hol jártunk már, de erre a nagyobb gráfra most nem lesz szükségünk.

A játékot ezen a gráfon egy, az $s$ csúcsból induló út ír le, hiszen a játékosok felváltva lépnek adott élek mentén és sosem ismételhetnek csúcsot. Ezért a gráfnak csak az $s$-t tartalmazó komponense érdekes, a többit szintén törölhetjük.

Látható, hogy a gráf páros, hiszen él csak olyan bitsorozatok között lehet, ahol az $1$-esek darabszámának a paritása különbözik.

Ötlet: Nyerő stratégia lehet a kapott gráfban valamilyen maximális párosítás élei mentén lépni. Például Alice megteheti azt, hogy keres egy maximális párosítást, ami az $s$-t tartalmazza, majd az $s$-hez tartozó párosításbeli élen kezdi a játékot, amire Bobnak muszáj lesz egy nem párosításbeli éllel válaszolnia és így tovább, amíg van még nem bejárt szomszédja az aktuális csúcsnak.

Megfigyelhető, hogy Alice és Bob éppen a javítóutas algoritmust futtatják: mindketten felváltva bővítgetik a saját párosításukat a következő lépésükkel, az általuk közösen bejárt út pedig egy alternáló út lesz mindkettőjük szemszögéből nézve.

Állítás: Ha a gráf minden maximális párosítása tartalmazza $s$-t akkor Alice fog nyerni, ellenkező esetben pedig Bob.

Indoklás: Ha minden maximális párosítás tartalmazza $s$-t, akkor Alice stratégiája az, hogy a játék elején választ egy ilyen maximális párosítást és az ő körében mindig az aktuális csúcshoz tartozó párosításbeli él mentén lép. 

Belátható, hogy ilyen lépés mindig létezik, hiszen ha egy adott játék során lenne Bobnak olyan lépése, amire Alice nem tud párosításbeli éllel válaszolni, akkor ez a játék egy olyan alternáló utat írna le, aminek mentén Bobnak ugyanannyi saját éle van mint Alice-nak, tehát ha Alice párosításában lecserélnénk az út menti éleket Bob éleire, azzal egy $s$-t nem tartalmazó maximális párosítást kapnánk a gráfban, ami ellentmondás.

Ha azonban van olyan maximális párosítás, ami nem tartalmazza $s$-t, akkor az tartalmazza $s$ minden szomszédját, különben bővíthető lenne a kimaradó éllel. Ekkor Bob stratégiája ennek a párosításnak az éleivel válaszolni Alice lépéseire.

Belátható, hogy Bob mindig tud így lépni, hiszen ha egy adott játék során lenne Alice-nak olyan lépése, amire Bob nem tud párosításbeli éllel válaszolni, akkor ez a játék egy javítóutat ír le Bob párosításához, tehát az nem lehetett maximális.

$\square .$

Algoritmus: Keressünk a javítóutas algoritmussal egy maximális párosítást az $s$-t nem tartalmazó gráfban, majd nézzük meg, hogy $s$-t visszatéve az javítható-e. Ha igen, akkor Alice fog nyerni, ellenkező esetben Bob.

Lépésszám: A gráf csúcsainak száma legfeljebb $v \in O(2^n)$, a max fokszám pedig $O(n)$, tehát az élszám $e \in O(n 2^n)$. Az algoritmusunk $O(ve) = O(n 4^n)$ lépésben fut, ami $n=10$-re még hihetően kicsi, például a $10^7 \approx 1$ másodperc ökölszabályt használva még $~1$ mp környékén van.
