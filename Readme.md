# C++ Basic Examples

In diesem Repository sind zahlreiche kleinere C++&ndash;Programme abgelegt,
um diverse Features von C++ zu demonstrieren.

Im Gro�en und Ganzen wurde dabei versucht,
die Beispiele auf dem Niveau f�r C++-Einsteiger
(mit Kenntnissen anderer Programmiersprachen wie zum Beipiel C oder Java) zu halten.

## Inhaltsverzeichnis:

#### [Klasse *Time*](Examples/Time/Resources/Readme.md)

Folgende Aspekte werden betrachtet:
  * Prinzipielle Realisierung einer einfachen Klasse *ohne* dynamische Daten im Instanzvariablenbereich
  * Zugriffsrechte (`private`, `public`)
  * �berladen von Operatoren
  * `friend`-Mechanismus
  * getter/setter-Methoden

---

#### [Klasse *Fraction*](Examples/Fraction/Resources/Readme.md)

Folgende Aspekte werden betrachtet:
  * Prinzipielle Realisierung einer einfachen Klasse *ohne* dynamische Daten im Instanzvariablenbereich
  * Zugriffsrechte (`private`, `public`)
  * �berladen von Operatoren
  * `friend`-Mechanismus
  * getter/setter-Methoden
  * Klassenmethoden

---

#### [Eine Klasse *IntegerSet*](Examples/IntegerSet/Resources/Readme.md)

Folgende Aspekte werden betrachtet:
  * Realisierung einer Klasse mit dynamischen Daten im Instanzvariablenbereich (Variante 1)
  * Realisierung einer Klasse mit einem STL-Container (`std::vector`) im Instanzvariablenbereich (Variante 2)
  * Korrekte Verwaltung dynamischer Daten einer Klasse ("*Big-Three*")
  * Verbesserung des Laufverzeitverhaltens: Implementierung der Move-Semantik ("*Big-Five*" / Variante 3 und 4)
  * Betrachtung des *Swap-Idioms* als eine M�glichkeit zur Umsetzung der Move-Semantik

---

#### [Klasse *String*](Examples/String/Resources/Readme.md)

Folgende Aspekte werden betrachtet:
  * Prinzipielle Realisierung einer einfachen Klasse *mit* dynamischen Daten im Instanzvariablenbereich
  * Konstruktoren und Destruktor im Zusammenspiel (*Big&ndash;Three*)
  * Zugriffsrechte (`private`, `public`)
  * �berladen von Operatoren
  * `friend`-Mechanismus

---

#### [Bankkonten und -institut](Examples/AccountsAndBank/Resources/Readme.md)

Folgende Aspekte werden betrachtet:
  * �bung zum Thema "Vererbung"
  * Die Konzepte zum Vererben und �berschreiben von Methoden werden an einem realistischen Beispiel demonstriert.
  * STL-Container `std::vector`

---

#### [Klasse `Phonebook`](Examples/PhoneBook/Resources/Readme.md)

Folgende Aspekte werden betrachtet:
  * Entwicklung einer Anwendung mit der STL (*Standard Template Library*)
  * Anwendung elementarer STL-Container (`std::vector`)
  * Anwendung elementarer STL Algorithmen (`std::find_if`, `std::copy_if`, `std::remove_if`, `std::sort`, `std::accumulate`, `std::for_each`)
  * Das Iteratoren-Konzept (Methode `import`)
  * Einsatz von Funktoren (*Callable Objects*)
  * Klasse `std::ostringstream`
  * Sortieren (`std::sort`)
  * Definition einer Schnittstelle (`IPhoneBook`)

---