# Beispiel Klasse `Rectangle`

## Einf�hrung

Definieren und implementieren Sie eine Klasse `Rectangle`,
die ein Rechteck im Sinne des kartesischen Koordinatensystems beschreibt.
Das Rechteck soll dabei durch zwei Punkte (x<sub>1</sub>, y<sub>1</sub>) und (x<sub>2</sub>, y<sub>2</sub>) festgelegt werden,
die die linke obere und rechte untere Ecke markieren.

Folgende Anforderungen an die Klasse `Rectangle` sind mit geeigneten programmiersprachlichen Konstrukten umzusetzen:

* Bei der Erzeugung eines `Rectangle`-Objekts mit dem Standard-Konstruktor werden beide Koordinaten auf den Wert (0, 0) gesetzt.

* Bei der Erzeugung eines `Rectangle`-Objekts mit einem benutzerdefinierten Konstruktor werden die Koordinaten entsprechend der Parameter des Konstruktors gesetzt.
  Dabei soll f�r zwei Punkte (*x*<sub>1</sub>, *y*<sub>1</sub>) und (*x*<sub>2</sub>, *y*<sub>2</sub>) im Objekt stets gelten:
  *x*<sub>1</sub> &le; *x*<sub>2</sub> und *y*<sub>1</sub> &ge; *y*<sub>2</sub>.
  Erf�llen die als Parameter �bergebenen Koordinaten diese Eigenschaft nicht,
  so sind im Objekt zwei modifizierte Punkte an Hand der Original-Punkte abzuleiten.
  Mit dieser Forderung soll erreicht werden, dass die beiden Punkte im Objekt stets die linke obere
  und rechte untere Ecke des Rechtecks beschreiben.
  Die Implementierung der nachfolgend beschriebenen Methoden vereinfacht sich auf diese Weise nicht unerheblich!

* Erg�nzen Sie die Klasse um *getter*- und *setter*-Methoden zum Lesen und Schreiben der Koordinaten des Rechtecks.
  Achten Sie darauf, dass beim �ndern einer Koordinate
  die zwei Regeln &ldquo;x<sub>1</sub> &le; x<sub>2</sub>&rdquo; und &ldquo;y<sub>1</sub> &ge; y<sub>2</sub>&rdquo; beibehalten bleiben.

* �berladen Sie den Operator `operator<<` geeignet, um `Rectangle`-Objekt in der Konsole ausgeben zu k�nnen.

* Schreiben Sie eine Methode `circumference` zur Berechnung des Umfangs eines Rechtecks.

* Die Methode `diagonal` berechnet die L�nge der Diagonalen des Rechtecks.

* Schreiben Sie eine Methode `area` zur Berechnung der Rechteckfl�che.

* Die Methode `isSquare` �berpr�ft, ob das Rechteck ein Quadrat ist oder nicht.

* Schreiben Sie eine Methode `center`, die den Punkt im Zentrum des Rechtecks berechnet.
  �bergeben Sie zu diesem Zweck die Adressen zweier `double`-Variablen an die Methode,
  um dort das Resultat ablegen zu k�nnen. Alternativ k�nnen Sie eine Klasse `Point` definieren,
  die von der `center`-Methode als R�ckgabetyp verwendet wird.

* Schreiben Sie eine Methode `adjustWidth`, die die Breite eines Rechtecks �ndert: *x*<sub>2</sub> = *x*<sub>1</sub> + *width*.

  *Beispiel*: F�r ein Rechteck mit den Koordinaten (1, 1) und (4, 5) besitzt nach dem Aufruf `adjustWidth(10);`
  die Koordinate *x*<sub>2</sub> den Wert 11.

* Schreiben Sie eine Methode `adjustHeight`, die die H�he eines Rechtecks �ndert:

  *y*<sub>2</sub> = *y*<sub>1</sub> - *height*.

* Erg�nzen Sie den Operator `operator<<` um weitere Angaben wie zum Beispiel Informationen zur Fl�che und zum Umfang,
  zur Diagonalen und dar�ber, ob das Rechteck ein Quadrat ist.

* Schreiben Sie eine Methode `intersection`, die ein zweites `Rectangle`-Objekt als Parameter �bergeben bekommt
  und dasjenige Rechteck berechnet, das die beiden Rechtecke gemeinsam haben.
  Das Resultat-Rechteck ist als R�ckgabewert der `intersection`-Methode zur�ckzuliefern.

*Beispiel*:

<pre>
Rectangle rect1(1, 4, 4, 1);
Rectangle rect2(2, 5, 6, 2);
Rectangle rect = rect1.Intersection(rect2);
</pre>

liefert ein Rechtecht `rect` mit den Eckpunkten (2, 4) und (4, 2) zur�ck.

* Schreiben Sie eine Methode `move`, die ein Rechteck in *x*- und/oder *y*-Richtung verschieben kann:

*Beispiel*:

<pre>
Rectangle rect(1,1,4,5);
rect.MoveTo(3, 6);
</pre>

Das Rechteck `rect` wird um 3 in *x*- und 6 in *y*-Richtung verschoben.

---

Im L�sungsteil der Aufgabe stellen wir zwei L�sungen zu dieser Aufgabe vor.
Eine erste L�sung setzt die Anforderungen der Aufgabenstellung direkt in eine Klasse `Rectangle` um.
In einer zweiten L�sung erstellen wir zwei Klassen `Point` und `Rectangle`.
Dabei m�ssen wir in C++ die Aspekte einer *Aggregation* beachten bzw. umsetzen,
da ein Objekt des Typs `Rectangle` dann zwei Unterobjekte des Typs `Point` f�r die beiden Eckpunkte besitzt.
Da &ndash; zumindest in diesem Beispiel &ndash; `Point`-Objekte prinzipiell
auch ohne umgebendes `Rectangle`-Objekt in Erscheinung treten k�nnen,
haben wir es nicht mit einer *Komposition* als Sonderfall der *Aggregation* zu tun.

---

*Hinweis*:
Der Quellcode im Repository zu dieser �bung ist bewu�t sehr elementar gehalten.
Oder um es anders zu formulieren: Viele der syntaktischen Neuerungen von C++ 11/14/17/20
sind bewu�t au�er Acht gelassen worden.
Es ist dem interessierten Leser �berlassen, diese Neuerungen einzuarbeiten.

---

[Zur�ck](../../../Readme.md)

---
