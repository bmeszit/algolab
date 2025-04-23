# Bitjáték [ELMÉLET]

Alice és Bob egy n hosszú bináris stringgel játszanak. Felváltva lépnek, minden körben az aktuális játékosnak választania kell egy bitpozíciót és invertálnia az ott lévő bitet. Van $k$ darab tiltott bitsorozat, amit senkinek nem szabad előállítani, továbbá minden bitsorozat legfeljebb egyszer állhat elő a játék során.

A bitstring kezdeti értékét jelölje $s$ és legyen Alice a kezdőjátékos. Mindkét játékos optimálisan játszik. Adjunk hatékony algoritmust, ami eldönti ki fog nyerni, ha tudjuk, hogy $n$ kicsi, $n \leq 10$.

## Példa

Legyen $n=2$, a kezdő pozíció $s=00$ és $k=2$ darab tiltott sorozat az $10$ és az $11$ legyenek. Ekkor Alice fog nyerni, hiszen ő meglépi a $01$-et és Bob semmi olyat nem fog tudni lépni ami nincs kitiltva vagy nem szerepelt már valamikor a játék során.
