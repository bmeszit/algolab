# Elméleti feladatok

## Beküldés

- Az elméleti feladatokra a megoldást bármilyen szöveges fájl (pl. `.md`, `.txt`, esetleg scannelt kép) formájában feltölthetitek.
  - Nekem kényelmesebb, ha gépelt szöveget kapok, mert például ha segítséget kértek, könnyebben meg tudom jelölni a problémás részeket PR-ban és látom a git historyban mi változott.

### Matematikai szimbólumok Markdown-ban

- A Github és a VSCode Markdown megjelenítője tud Latex matematikai szimbólumokat renderelni, ezt érdemes használni, például:
  - $$x_{1,2} = \frac{-b \pm \sqrt{b^2 - 4ac}}{2a}$$
  - Az összefésüléses rendezés lépésszáma $\mathcal{O}(n\log n)$.
  - $n$-ből $k$ elem kiválasztása ismétlés nélkül $\binom{n}{k}$ féleképpen lehetséges.
- Ha szükségetek van egy szimbólumra, ez a weboldal kézi rajz alapján megkeresi nektek a megfelelő parancsot: https://detexify.kirelabs.org/classify.html

### Értékelés

- Az Algoritmuselmélet ZH-k pontozásához hasonló módon történik.
- Egy algoritmusnál le kell írni:
  - Milyen adatszerkezeteket használtok és mik a lépések.
    - Olyan módon, hogy egy tapasztalt programozó a leírás alapján implementálni tudja azt.
  - Helyesség és a lépésszám indoklása.
    - Olyan részletességgel, amivel egy szkeptikus szobatársatokat meg tudnátok győzni az igazatokról.
- Részpontszám van, az alapján dől el mennyire vagytok messze egy teljes értékű megoldástól.
- Reklamációra a félév közben van lehetőség, érdemes azért nem sokkal a
