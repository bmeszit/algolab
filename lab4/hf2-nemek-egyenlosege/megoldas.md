# Nemek egyenlősége

Ötlet: Bináris keresés a megoldásra.

1\. Számítsuk ki először a fiú-optimális és lány-optimális stabil párosítást.

Belátjuk, hogy ezek a gráf minden csúcsát fedni fogják.

Ha a fiú-optimális stabil párosításban lenne kimaradt fiú, az azt jelenti hogy ő mind az $n$ lányt felkérte és mindegyik elutasította őt. Azonban egy lány csak akkor utasít el, ha valaki más felkéri, azaz mind az $n$ lányt fel kellett, hogy kérje egy másik (egymástól különböző) fiú, viszont csak $n-1$ másik fiú van, ez ellentmondás. Ha pedig nincs kimaradt fiú, nekik különböző lányok a párjaik, tehát nincs kimaradt lány sem.

Mivel tudjuk, hogy a stabil párosítások mindig ugyanazokat a csúcsait fedik a gráfnak, ezért a keresett maximális boldogtalanság minimalizáló stabil párosítás is a gráf összes csúcsát kell, hogy fedje.

A fiú-optimális és lány-optimális stabil párosítások ismeretében pedig mostmár tudjuk, hogy kinek mi a legjobb elérhető éle.

2\. Készítsünk egy segédeljárást, ami azt csinálja, hogy az eredeti $G$ gráfban a fiúk és a lányok preferencialistáinak a végéről elhagyja azokat az éleket, amik egy adott boldogtalansági szint felettiek a legjobb elérhető él ismeretében és ezen a $G'$ csonkolt gráfon keressünk egy (fiú-optimális) stabil párosítást a lánykérő algoritmussal!

Belátható a következő két állítás:

(1) Ha a $G'$-ben kapott stabil párosítás szintén fedi az összes csúcsot, akkor az stabil párosítás lesz az eredeti $G$-ben is.  
(2) Ha a $G'$-ben kapott stabil párosítás nem fedi az összes csúcsot, akkor az adott boldogtalansági szinthez nem létezik stabil párosítás $G$-ben.

(1) Biz.:

Tegyük fel indirekt, hogy a $G'$-ben kapott stabil párosítás szintén fedi az összes $G$-beli csúcsot, de mégsem stabil $G$-ben. Ez azt jelenti, hogy $G$-ben létezik hozzá blokkoló $(u,v)$ él, ez pedig valamelyik törölt él kell, hogy legyen.

Tegyük fel, hogy ezt az $(u,v)$ élet $u$ miatt töröltük, azaz $u$ esetében ez az él az optimális éléhez képest túl nagy boldogtalansághoz vezetne. Mivel a $G'$-beli stabil párosítás fedi $u$-t, ezért $u$-hoz tartozik benne valamilyen $(u, w)$ él. Mivel $(u,w)$-t nem töröltük, ezért $u$-nak a listájában $w$ előrébb kell, hogy legyen $v$-hez képest, ezért az $(u,v)$ él nem tudja blokkolni ezt a párosítást $G$-ben, ez pedig ellentmondás.

(2) Biz.:

Ha a $G'$-ben kapott stabil párosítás nem fedi az összes csúcsot, akkor az biztosan nem stabil $G$-ben. Ha lenne az adott boldogtalansági szinthez stabil párosítás $G$-ben, akkor ennek az élei benne lennének $G'$-ben is, ahol pedig szintén stabil lenne, de biztosan nincs benne, hiszen ez fedné az összes csúcsot, de $G'$ stabil párosításai nem fedik az összes csúcsot.

3\. Bináris kereshetőség:

Ha egy adott boldogtalansági szintre van megoldás, akkor az nyilván megengedőbb, magasabb szintre is megoldás lesz. Tehát létezik egy határvonal, ami felett megoldható a feladat és ami alatt nem, ezt lehet binárisan keresni.

Ezzel $O(n^2 \log n)$-es algoritmust kaptunk, mivel a lánykérő algoritmus $O(n^2)$, a bináris keresés az $n$ lehetséges boldogtalansági szintre $O(\log n)$-szer fogja lefuttatni, az egyéb műveletek: a fedettség ellenőrzése, illetve az élek elhagyása a preferencialisták végéről pedig szintén megvan $O(n^2)$-ben.

Ha valaki lineáris keres, azaz minden lehetséges boldogtalanságot kipróbál azt is elfogadjuk, ha a 2\.-es indoklása helyes.
