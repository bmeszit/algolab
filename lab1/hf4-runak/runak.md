# Mágikus rúnamátrix

Amelyik sorban és oszlopban nem szerepel a $0$, azoknak $0$ a MEX-e, ezek nem járulnak hozzá a végső értékhez.

A $0$ pontosan egy cellában szerepel, tehát az ő sorában és az oszlopában van esélyünk nem $0$ értéket kapni. Az $1$-es szám vagy csak a sorában vagy csak az oszlopában szerepelhet, amelyikben nem szerepel, annak $1$ a MEX-e.

Ezek után azt a sort vagy oszlopot amiben a $0$ és $1$ is szerpel úgy tudjuk maximalizálni, hogyha sor esetében a $0$ és $m-1$ számokat írjuk bele, ezzel $m$ lesz a MEX, oszlop esetében pedig hasonlóan eljárva $n$ lesz a MEX.

A két lehetőség közül a maximálisat kell választani, tehát a végső MEX $max(n,m)+1$.
