# Mágus Misi és a félrement permutáció varázslat

- Tegyük a sorokat a Misi által kiszámolt ár szerinti csökkenő sorrendbe és csoportosítsuk az azonos árúakat!
- Azok a tulajdonosok akik a legmagasabb árkategóriában vannak a piaci egyensúly definíciója alapján a preferencialistájuk első elemét veszik meg. Tehát tudjuk, hogy ebben a csoportban a preferencialistákban az első helyen lévő házak voltak eredetileg is szétosztva valahogyan.
  - Nem fordulhat elő tehát az, hogy ebben a csoportban a preferencialisták elején több helyen is ugyanaz a lakás szerepel, ilyenkor Misi elszámolt valamit és vallania kell.
  - Eredetileg bármilyen permutációban lehettek a lakások, ha $k_1$ elemű ez a csoport, akkor $k_1!$ féle kezdeti elosztás jöhet szóba, ezek közül kell egyet kiírni (például az identitást).
- Ezután ezeket a házakat törölni kell az összes többi preferencialistából.
  - Praktikusan csak nyilvántartunk egy segédtömböt amiben feljegyezzük, ha valamelyik elemet töröltük és amikor egy preferencialista legjobb elemét keressük, akkor addig iterálunk rajta, amíg találunk egy nem törölt jelzésűt.
- Majd ezt ismételjük a következő árcsoportra, amíg el nem fogynak.

Lépésszám:

- A sorrendezés $O(n \log n)$-ben történik.
- Minden csoportra megkeressük a preferencialisták első nem törölt jelzésű elemét, ez az összes csoportra összesen $O(n^2)$.
- Ezután minden csoportra ellenőrizzük, hogy a preferencialisták első elemei között nincsenek duplikációk, ez szintén $O(n \log n)$, mert csoportonként 1-1 rendezést lehet futtatni.
- Végül minden csoportra kiírunk egy lehetséges megoldást, legegyszerűbben például azt, ahol mindenki saját magát kapja meg, ez $O(n)$.

Összesen tehát $O(n^2)$ az algoritmus.

A lehetséges megoldások darabszáma pedig a csoportok méretének a faktoriálisa, összeszorozva az összes csoportra, kivéve persze ha menet közben kiderül, hogy nincs megoldás.
