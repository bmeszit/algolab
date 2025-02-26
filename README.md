# Algolab

## Tervezett menetrend

A későbbi témakörök képlékenyek, erősen attól függenek, hogy a korábbi laborokon hogyan haladtunk, hogy sikerültek a házik.

| Labor | Dátum            | Terv                                           |
| ----- | ---------------- | ---------------------------------------------- |
| Lab1  | 2025\. 02\. 12\. | Rekurziók, keresés, rendezés                   |
| Lab2  | 2025\. 02\. 26\. | Gráfalgoritmusok: BFS, DFS, Dijkstra           |
| Lab3  | 2025\. 03\. 12\. | DSU, Kruskal, Párosítások (?)                  |
| Lab4  | 2025\. 03\. 26\. | Stabil párosítások, Folyam (?)                 |
| Lab5  | 2025\. 04\. 09\. | Játékelm. algok (?)                            |
| Lab6  | 2025\. 04\. 30\. | Találjunk ki HEX stratégiákat                  |
| Lab7  | 2025\. 05\. 14\. | HEX verseny, HF nincs                          |

## Programozási feladatok

- C++ vagy Python nyelven oldhatók meg.
- A tesztesetek megoldásokkal együtt publikusak, ez nektek segítség.
  - A programkódot el fogom olvasni, ha nem általános, pl. bemenet string matchre az ismert kimenet string kiírása, akkor 0 pont. :)
- Tesztesetenként a limitek:
  - Idő: 5 mp, Memória: 512 MB
  - Ezek kicsit megengedőbbek a feladat forrásokhoz képest.

### Tesztelés

Verdictek:

- OK
- WA = Wrong Answer
- TLE = Time Limit Exceeded
- MLE = Memory Limit Exceeded
- RE = Runtime Error
  - Jelenleg, ha a time/memory limit 2x-esét meghaladja, akkor is RE, de ezt próbálom javítani.

### Tesztelő futtatása

Lokálisan:

- Linuxon: `eval.sh <mappa>` Lefuttatja az adott mappára a teszteket.
- Más operációs rendszeren: Docker telepítése után `eval_docker.sh <mappa>`.

Pull requestben:

- Mindig az adott laborra lefut az `eval.sh`.

Github actionben:

- Workflow triggerrel futtatható, tetszőleges mappanévre.

## Források

A feladatok forrásai a következő weboldalak:

- [CSES](https://cses.fi/problemset)
- [Codeforces](https://codeforces.com)
- [LeetCode](https://leetcode.com)
