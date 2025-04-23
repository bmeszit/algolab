# Mágus Misi

Vegyük először észre, hogy ha Misi részt szeretne venni egy olyan kihíváson, ami csökkenti az energiáját,
akkor érdemes ezt minnél későbbi napra halasztania, hiszen a köztes időszakban magasabb energiával 
több olyan nap is lehet, ami nem csökkenti az energiáját. Precízebben mondva, egy tetszőleges optimális
megoldást átalakíthatunk úgy, hogy az energiacsökkentő napokat kivesszük belőle, majd a nem kiválaszott
napok közül hátulról előrefelé haladva kiválasztunk ugyanennyi darabot. Az átalakítás után minden napra
igaz, hogy  Misi adott napi energiája vagy változatlan maradt vagy nőtt, tehát a megoldás legálisságát
nem rontottuk el.

Az így hátulra tömörített megoldások tehát felbonthatók két szakaszra: az első szakaszban Misi 
csak olyan kihívásokat vállal el, ahol nem csökken az energiája, a második szakaszban pedig
minden kihívást elvállal.

A továbbiakban tehát elég egy ilyen alakú optimális megoldást keresünk. Egyetlen kérdést kell csak megválaszolnunk:
melyik napon váltson Misi stratégiát, hogy ne fogyjon el a vége előtt az energiája?

## Első megoldás, bináris kereséssel

Látható, hogy ha az $i$. napi stratégiaváltás legális megoldást eredményez, akkor minden $i$.-nél későbbi
nap is legális lesz, hiszen ugyanannyi vagy több energiája marad Misinek. Egy optimális megoldás a lehető legkorábbi
stratégiaváltó nap, hiszen ez maximalizálja a kiválasztott napokat.

Keressük tehát a stratégiaváltó napot bináris kereséssel a lehetséges napok között! A két extrém esetet is
engedjük meg, tehát válthasson stratégiát az első nap előtt és az utolsó nap után is. Ez összesen $O(\log n)$
kör lesz. Ellenőrizzük le, hogy legális-e a kapott megoldás, ezt $O(n)$-ben megtehetjük. Ha az adott nap legális,
akkor folytassuk a keresést a megengedett intervallum alsó felében, egyébként pedig a felsőben.

## Második megoldás, megfordítva az idő irányát

Szimuláljuk le a folyamatot hátulról előrefele! Kezdjen Misi az $n$. napon $0$ energiával és fordítsuk meg a szabályokat:

- Ha Misi aktuális energiája még nem érte el a kiindulásit akkor vegyen részt minden kihíváson.
  - Ha az adott kihívás nehézségi szintje több mint az aktuális $M$ energia, akkor növeljük $M$-et $1$-el!
- Ha elértük a kiindulási $M$ energiát, akkor már csak azokon a kihívásokon vegyünk részt, amiknek a nehézségi szintje nem több $M$-nél.

Látható, hogy ezzel a módszerrel éppen a lehetséges leghosszabb második szakaszt állítjuk elő, ezzel pedig ugyanazt a megoldást
számoljuk ki mint az előző algoritmussal, azonban itt csak $O(n)$ lépésre volt szükség.

Szemfülesek észrevehetik, hogy előfordulhat olyan eset, amikor Misi aktuális energiája $x-1$ és egy $x$ nehézségű kihíváson
veszünk részt. Ekkor a hátrafele irányú algoritmus növeli Misi energiáját $x$-re, viszont az előrefele irányú esetben itt
nem csökkenne az energia. Ez pont olyankor van, amikor Misinek a kihívások befejeztével pozitív energiája marad, a 
visszairányú szimuláció ezen a ponton könyveli ezt el.
