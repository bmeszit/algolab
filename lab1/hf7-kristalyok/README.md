# Mágus Misi és a sötét kristályok [ELMÉLET]

Mágus Misi egyik reggel nagy bajban volt - az úton az Ősi Varázslók Akadémiája felé sötét energiából álló kristályoszlopok jelentek meg, teljesen eltorlaszolva az utat.

Az út $n$ egymást követő mezőből áll, az $i$. ($1 \leq i \leq n$) mezőben pontosan $a_i$ darab sötét kristály van. Szerencsére Misi ismeri a mágikus manóidézés ősi varázslatát, és képes $m$ darab energiamanót megidézni, akik segítenek neki megtisztítani az utat. A manók egymástól függetlenül, párhuzamosan dolgoznak. A varázslat kezdetekor minden manó a nulladik mezőn, materializálódik.

Minden manónak két lehetősége van a lépésre, mindkettő egy másodpercet vesz igénybe:
- Ha a manó épp az $i$. mezőn van, akkor átlebeghet az $i+1$. mezőre.
- Ha a manó épp az $i$. mezőn van, akkor megsemmisíthet egy darab ott lévő kristályt a mágiájával.

Mivel a megidézett manók csak korlátozott ideig maradhatnak a mi világunkban, ki kell számolnod a minimális $t$ időt másodpercekben, ami alatt el tudják tüntetni az összes sötét kristályt. A manók a $t$ másodperc letelte után bárhol lehetnek, csak az összes kristálynak el kell tűnnie addigra, mielőtt a manók is köddé válnak.

Adjunk hatékony algoritmust a feladatra! Ha $A = \sum\limits_i a_i$, akkor például jó lehet egy $O(\log(A+n) \cdot (A+n) \cdot m)$-s algoritmus (de ennél ügyesebben is lehet).

## Példa

### 1\. példa

$n=2$, $m=1$ esetén, ha a kristályok darabszáma $a_1=1, a_2=1$, akkor a feladatot $4$ másodperc alatt lehet megoldani.

Egyetlen manó van, aki az első körben odalép az első mezőre (1 mp), utána eltünteti az ott lévő kristályt (1 mp), majd odalép a következő mezőre (1 mp), majd onnan is eltünteti a kristályt (1 mp).

### 2\. példa

$n=3$, $m=2$ esetén, ha a kristályok darabszáma $a_1=1, a_2=0, a_3=2$, akkor a feladatot $5$ másodperc alatt lehet megoldani.

Az egyik lehetséges megoldás, hogy egy manó fog 1-1 kristályt eltüntetni az első és a harmadik mezőről, egy másik manó pedig a harmadik mezőről tűntet el egyet, összesen 5 mp alatt.

### 3\. példa

$n=4$, $m=100$ esetén, ha a kristályok darabszáma $a_1=3, a_2=4, a_3=5, a_4=4$, akkor a feladatot $5$ másodperc alatt lehet megoldani.

Nagyon sok manónk van, ezért megidézhet Misi pontosan $3+4+5+4$ manót és mindenki egyetlen kristályért indul el és távolítja el, ehhez összesen $5$ másodpercre van szükség.
