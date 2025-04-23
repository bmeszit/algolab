# Mágus Misi [ELM]

Mágus Misit a Nagy Misztikus Akadémia hívta, hogy vegyen részt egy sor varázslatos megpróbáltatáson.

Összesen $n$ próba van és mindegyikhez tartozik egy kihívási szint. Az $i$. próbára az $i$. napon kerül sor és $x_i$ nehézségi szint tartozik hozzá. Misit a kaland kezdete előtt ellenséges erők ellenére megillette a bátorság és a varázserő, így kezdetben amágikus energiája $M$.

Misi célja, hogy **minél több megpróbáltatáson vegyen részt**, nem számít hogy a próbák végén Misinek mennyi energiája marad.

Az $i$. napon Misi előtt két lehetőség áll: megpróbálja a megpróbáltatást, vagy inkább kihagyja azt. Fontos azonban, hogy ha Misi energiája teljesen elfogyik, azaz $0$-ra csökken, akkor azonnal haza kell mennie aludni és nem tud tovább részt venni a próbákon.

A szabályok a következők:

- Ha Misi nekivág az $i$. megpróbáltatásnak:
  - Ha $M < x_i$, azaz a próba $x_i$ nehézségi szintje nagyobb, mint Misi aktuális $M$ mágikus energiája, akkor Misi ráébred gyengeségére és ennek következtében $1$ egységgel csökken az energiája.
  - Ha $x_i \leq M$, akkor Misi sikeresen végrehajtja a próbát és energiája változatlan marad.
- Ha Misi úgy dönt, hogy inkább kihagyja az aznapi megpróbáltatást, akkor semmi sem változik, a mágikus energiája ugyanannyi marad.

Segíts Misinek, adj egy algoritmust ami meghatározza, hogy mely napokon kísérje meg a megpróbáltatásokat (és mely napokat hagyja ki), így elérve, hogy Misi a lehető legtöbb próbán részt tudjon venni! Misinek már nem sok ideje maradt a próbák kezdetéig, ezért $O(n \log n)$-es futásidejű algoritmusra van szüksége, de ha ügyes vagy, akkor $O(n)$-ben is meg tudod oldani a feladatot. Az algoritmus helyességét és lépésszámát indokold is meg.
