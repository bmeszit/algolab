## Programozási feladatok

### Beküldés

- C++ vagy Python nyelven oldhatók meg.
- A forráskódot a `main` branchen feladat mappájának gyökerébe kell elhelyezni, tetszőleges névvel, a programozási nyelvnek megfelelő kiterjesztéssel (`.cpp` vagy `.py`).
- Minden laborhoz tartozni fog egy pull request, amit én hozok létre.
  - A beadási határidőig itt @nemkin-el megtagelhettek, ha bármilyen kérdésetek van, vagy segítségre lenne szükségetek, szívesen ránézek az eddigi beadott szövegekre / kódokra!
    - Ezekre próbálok értelmes tempóban reagálni.

### Értékelés

- A kódokhoz tartozik automatizált tesztelés is (lásd kicsit lentebb), ennek célja, hogy titeket segítsen a feladatok önálló megoldásában, azonban a végső pontszám manuális értékelés alapján dől el.
- A beadott kódjaitokat tehát el fogom olvasni és a következő szempontok alapján értékelek:
  - Nem az számít, hogy a tesztesetek hány százaléka lett sikeres vagy sikertelen, hanem az, hogy milyen messze vagytok a helyes megoldástól, milyen mennyiségű és nehézségű ötlet hiányzik, milyen horderejű hibák vannak a kódban.
  - Előfordulhat, hogy nagyon sok a WA, viszont a kódban csak egy apróság volt elnézve, ekkor nem sok pontot vonnék le.
  - Ha elvi hibát tartalmaz, amit az automatizált tesztek nem szűrtek ki, vagy csak 1-2 teszteset lett WA, akkor is több pontot vonnék le, hiába néz ki "majdnem jónak" a megoldás.
  - Ha nem általános, például ha a publikus teszteseteket string matching algoritmussal felsimeri és kiírja rá a publikus választ, akkor 0 pont. :)

#### Automatizált tesztek

- Az automatizált értékeléshez tesztesetek tartoznak, amelyek a feladat mappáján belül `tesztek/*.in` néven vannak elmentve.
  - Az algoritmikus programozási versenyeken a tesztesetek nem szoktak publikusak lenni, azonban ezen a laboron elérhetővé tettem őket, ez nektek segítség a debuggolásban.
- Tesztesetenként a limitek:
  - Idő: 5 mp, Memória: 512 MB
  - Ezek kicsit megengedőbbek a feladat forrásokhoz képest.
- Lehetséges verdictek:
  - OK
  - WA = Wrong Answer
  - TLE = Time Limit Exceeded
  - MLE = Memory Limit Exceeded
  - RE = Runtime Error
    - Jelenleg, ha a time/memory limit 2x-esét meghaladja, akkor is RE, de ezt próbálom javítani.
- A pull requestben mindig le fog futni az adott labor mappájára az `eval.sh`, ha feltöltötök a `main` branchre valamit, ez automatikusan ellenőrzi a tesztesetekre adott válaszotokat.
  - Részletek, lokális tesztelés bővebben: [tesztelo_script.md](./tesztelo_script.md).
