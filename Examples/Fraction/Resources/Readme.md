# Beispiel Klasse `Fraction`

## Einf�hrung

In dieser �bung wollen wir uns der Klasse `Fraction` in einer zusammenfassenden Betrachtung annehmen.

---

*Hinweis*:
Der Quellcode im Repository zu dieser �bung ist bewu�t sehr elementar gehalten.
Oder um es anders zu formulieren: Viele der syntaktischen Neuerungen von C++ 11/14/17/20
sind bewu�t au�er Acht gelassen worden.
Es ist dem interessierten Leser �berlassen, diese Neuerungen einzuarbeiten.

---

Folgenden Eigenschaften sollen in Ihrer Realisierung der Klasse `Fraction` Ber�cksichtigung finden:

  * Objekte der Klasse `Fraction` sollen die von ihr verwaltete rationale Zahl immer in einer
    optimal gek�rzten Form verwalteten. Schreiben Sie dazu eine Methode `reduce`, die den
    Bruch optimal k�rzt.

  * Rationale Zahlen k�nnen sowohl positiv als auch negativ sein. Um die klasseninterne
    Arbeitsweise der einzelnen Methoden zu vereinfachen, soll die Regel gelten, dass der
    Nenner einer rationalen Zahl immer positiv ist. Damit kann der Z�hler eines
    `Fraction`-Objekts in Abh�ngigkeit vom Vorzeichen der rationalen Zahl entweder positiv
    oder negativ sein. Achten Sie darauf, dass bei allen �nderungen am Objektzustand (zum
    Beispiel nach einer Subtraktion) der Nenner positiv ist.

  * G�ngige Konstruktoren zur Objekterzeugung.

  * Implementieren Sie die folgenden mathematischen Rechenoperationen:
    * Grundrechenoperationen (`+`, `-`, `*` und `/`).
    * Grundrechenoperationen in Verbindung mit dem Zuweisungsoperator (`+=`, `-=`, `*=`, `/=`).
    * Inkrement- und Dekrementoperator (`++` und `--`).
    * Inverse einer rationalen Zahl (Operator `~`).
    * Un�rer Minus-Operator (`-`).
    * Vergleichsoperatoren (`==`, `!=`, `<`, `<=`, `>` und `>=`).

  * Methode `gcd` (*greatest common divisor*) zur Bestimmung des gr��ten gemeinsamen Teilers von Z�hler und Nenner (*ggT*).
    Die `gcd`-Methode kann von der `reduce`-Methode verwendet werden.

  * Operatoren zur Typumwandlung: Ein `Fraction`-Objekt soll in einem arithmetischen
    Ausdruck auch dann verwendet werden k�nnen, wenn auf Grund des Kontextes ein `float` oder
    `double`-Wert erwartet wird.

  * Ein- und Ausgabe: Eine rationale Zahl soll in der Form &ldquo;Z�hler / Nenner&ldquo; ausgegeben werden.
    F�r Eingaben ist dasselbe Format zu Grunde zu legen. Zwischen den numerischen
    Werten und dem Schr�gstrich sind beliebige Leerzeichen und Tabulatoren erlaubt.

---

[Zur�ck](../../../Readme.md)
