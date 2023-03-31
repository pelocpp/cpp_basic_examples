# C++ Basic Examples

In diesem Repository sind zahlreiche kleinere C++&ndash;Programme abgelegt,
um diverse Features von C++ zu demonstrieren.

Im Großen und Ganzen wurde dabei versucht,
die Beispiele auf dem Niveau für C++-Einsteiger
(mit Kenntnissen anderer Programmiersprachen wie zum Beipiel C oder Java) zu halten.

## Inhaltsverzeichnis:

#### [Klasse *Time*](Examples/Time/Resources/Readme.md)

Folgende Aspekte werden betrachtet:
  * Prinzipielle Realisierung einer einfachen Klasse *ohne* dynamische Daten im Instanzvariablenbereich
  * Konstruktoren
  * Zugriffsrechte (`private`, `public`)
  * Überladen von Operatoren
  * `friend`-Mechanismus
  * *getter*/*setter*-Methoden
  * Objekte als Rückgabewert von Methoden

---

#### [Klasse *Fraction*](Examples/Fraction/Resources/Readme.md)

Folgende Aspekte werden betrachtet:
  * Prinzipielle Realisierung einer einfachen Klasse *ohne* dynamische Daten im Instanzvariablenbereich
  * Konstruktoren
  * Zugriffsrechte (`private`, `public`)
  * Überladen von Operatoren
  * `friend`-Mechanismus
  * *getter*/*setter*-Methoden
  * Klassenmethoden

---

#### [Klasse *Rectangle*](Examples/Rectangle/Resources/Readme.md)

Folgende Aspekte werden betrachtet:
  * Prinzipielle Realisierung einer einfachen Klasse *ohne* dynamische Daten im Instanzvariablenbereich
  * Konstruktoren
  * Zugriffsrechte (`private`, `public`)
  * *getter*/*setter*-Methoden
  * Realisierung einfacher Methoden
  * Objekte als Rückgabewert von Methoden

---

#### [Eine Klasse *IntegerSet*](Examples/IntegerSet/Resources/Readme.md)

Folgende Aspekte werden betrachtet:
  * Realisierung einer Klasse mit dynamischen Daten im Instanzvariablenbereich (Variante 1)
  * Realisierung einer Klasse mit einem STL-Container (`std::vector`) im Instanzvariablenbereich (Variante 2)
  * Korrekte Verwaltung dynamischer Daten einer Klasse ("*Big-Three*")
  * Verbesserung des Laufverzeitverhaltens: Implementierung der Move-Semantik ("*Big-Five*" / Variante 3 und 4)
  * Betrachtung des *Swap-Idioms* als eine Möglichkeit zur Umsetzung der Move-Semantik

---

#### [Klasse *String*](Examples/String/Resources/Readme.md)

Folgende Aspekte werden betrachtet:
  * Prinzipielle Realisierung einer einfachen Klasse *mit* dynamischen Daten im Instanzvariablenbereich
  * Konstruktoren und Destruktor im Zusammenspiel (*Big&ndash;Three*)
  * Zugriffsrechte (`private`, `public`)
  * Überladen von Operatoren
  * `friend`-Mechanismus

---

#### [Vererbung am Beispiel von Rechtecken](Examples/Rectangles/Resources/Readme.md)

Folgende Aspekte werden zum Thema &ldquo;Vererbung&rdquo; betrachtet:
  * Entwicklung einer Hierarchie von Klassen
  * Konstruktoren von abgeleiteten Klassen und Basisklassen
  * Verwendung von `public`, `protected` und `private`
  * Verdecken von Methoden
  * Überschreiben von Methoden
  * Schlüsselwörter `virtual`, `override` und `final`
  * Polymorphismus
  * Betrachtung einer Schnittstelle (*Interface*)
  * Kontrakt mit mehreren Schnittstellen
  * Betrachtung einer abstrakten Basisklasse 
  * Betrachtung von konkreten Klassen
  * Unterschied Schnittstelle versus abstrakte Basisklasse

---

#### [Bankkonten und -institut](Examples/AccountsAndBank/Resources/Readme.md)

Folgende Aspekte werden betrachtet:
  * Übung zum Thema "Vererbung"
  * Die Konzepte zum Vererben und Überschreiben von Methoden werden an einem realistischen Beispiel demonstriert.
  * STL-Container `std::vector`

---

#### [STL- Standard Template Library](Examples/STL/Resources/Readme.md)

Folgende Aspekte werden betrachtet:
  * Zwei einfache, einführende Beispiel zur STL (*Standard Template Library*)
  * Berechnung der Teuflischen Zahlenfolge und von Fibonacci Zahlen
  * Grundlegende STL-Konzepte: STL-Container, Iteratoren, STL-Algorithmen und Funktionsobjekte

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

## Literaturverzeichnis:

#### WebSite &ldquo;Learn C++&rdquo;

  * [Learn C++](https://www.learncpp.com/)

    Aus der Einführung:

    *&ldquo;LearnCpp.com is a free website devoted to teaching you how to program
    in C++. Whether you’ve had any prior programming experience or not,
    the tutorials on this site will walk you through all the steps to write,
    compile, and debug your C++ programs, all with plenty of examples.&rdquo;*

    *&ldquo;Becoming an expert won’t happen overnight, but with a little patience,
     you’ll get there. And LearnCpp.com will show you the way.&rdquo;*

---
