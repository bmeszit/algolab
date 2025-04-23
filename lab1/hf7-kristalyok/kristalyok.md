# Mágus Misi és a sötét kristályok

Alapötlet: keressük binárisan, hogy mennyi idő alatt lehet megcsinálni a feladatot!
(Nyilván, ha valamennyi idő alatt meg lehet, akkor többel is.)

Készítsünk egy teszter függvényt ami megmondja, hogy adott $t$ idő alatt megoldható-e a feladat.
A teszter függvény dolgozzon mohó módszerrel, a következő érvelés alapján:

- Tudjuk, hogy a legutolsó kristályt valamelyik manónak fel kell szedni.
- Ez a manó el fog menni a legutolsó kristályig, amire elhasznál $x$ időt.
- A maradék $t-x$ idővel menet közben gazdálkodhat, ennyi db kristályt levehet bárhonnan.
- Akkor járunk a legjobban, ha a végéről veszi le az összes kristályt, mivel a rákövetkező manók így lehet, hogy kevesebb időt pazarolnak majd lépésre. (Azaz bármilyen optimális megoldás átrendezhető olyan alakúra, hogy az utolsó manó a legvégéről szed le kristályokat és ezzel csak időt spóroltunk a többi manónak, tehát nem rontottuk el.)
- Ismételjük ezt az algoritmust az összes manóra, amíg el nem fogynak a dobozok!
- Ha ekkor $m$-nél kevesebb vagy egyenlő manót használtunk akkor meg lehet csinálni.

Következmény: Ha van optimális megoldás, akkor olyan is van amiben a manók egymást követő dobozokat vesznek le.

Ez pedig azt jelenti, hogy akár előről hátrafelé is végezhetjük a szimulációt, hiszen csak az a feltétel, hogy a manók egymást követő dobozokat vegyenek le, amíg van rá idejük.

Mivel manónként szimulálunk, ezért $m$-szer kell futtatni, egy manót pedig a tömb méretével lineárisan, $O(n)$-ben tudunk szimulálni, hiszen minden cellára konstans műveletet végez. Végül a bináris keresést a $[0, A+n]$ intervallumon végezzük, hiszen egy manóval $A+n$ lépésben lehet elvégezni a feladatot, ez pedig egy $O(\log(A+n))$-es szorzó, összesen tehát $O(\log(A+n) \cdot m \cdot n)$-es az algoritmus.

Ha a szimulációt ügyesen implementáljuk, akkor az nem fog az $m$ értékétől sem függeni. Ehhez az kell, hogy a mezőkön iteráljunk és manócsoportokat küldjünk a kristályok leszedésére az adott mezőre, úgy hogy mindig egy olyan manó maradhasson csak, akinek még van ideje továbbmenni. Mindig az előző körből maradt manó kezdi a felszedést, majd maradékos osztással eldöntjük hány egész manónyi munkát kell elhasználnunk az adott mezőért, végül a maradékot felszedő manó megy tovább a következő cellára. Ezzel az ötlettel pedig már $O(\log(A+n) \cdot n)$-es az algoritmusunk, de ezt már csak érdekességként jegyezzük meg.
