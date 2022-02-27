# Beispiel Klasse `Rectangle`

## Einf�hrung

Definieren und implementieren Sie eine Klasse `Rectangle`,
die ein Rechteck im Sinne des kartesischen Koordinatensystems verwaltet.
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
    die Regel &ldquo;x<sub>1</sub> &le; x<sub>2</sub>&rdquo; und &ldquo;y<sub>1</sub> &ge; y<sub>2</sub>&rdquo; beibehalten bleibt.


a) WEITER mit dem Text aus

https://peterloos.de/legacy/index.php/m-cpp/m-cpp-classes-objects/83-a-cpp-class-rectangle

b) Quellcode aufr�umen !!!!

c) Im Readme zum Gesamt Projekt fehlt dieses Beispiel !!!



---

*Hinweis*:
Der Quellcode im Repository zu dieser �bung ist bewu�t sehr elementar gehalten.
Oder um es anders zu formulieren: Viele der syntaktischen Neuerungen von C++ 11/14/17/20
sind bewu�t au�er Acht gelassen worden.
Es ist dem interessierten Leser �berlassen, diese Neuerungen einzuarbeiten.

---

[Zur�ck](../../../Readme.md)

---
