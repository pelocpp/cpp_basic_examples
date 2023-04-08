# Low-Level Programming in C/C++

Wir betrachten in diesem Programm eine Reihe von C/C++&ndash;Funktionen,
die in die Kategorie *Low-Level Programming* fallen.
Es werden die vier Operatoren zur Bitmanipulation (engl. *bitwise operators*) 
`&`, `|`, `^` und `~` sowie die beiden
Shift-Operatoren `<<` und `>>` an entsprechenden Beispielen vorgeführt.

Kleinere Funktion mit Anwendung der Bitmanipulationsoperatoren 
runden das Programm ab:


| Funktion | Schnittstelle und Beschreibung |
|:-------------- |-----------------------------------------|
| Funktion `setBit` | `void setBit(unsigned int value, int position);`<br/>Setzt in Variable `value` das Bit an Position `pos`. |
| Funktion `clearBit` | `void clearBit(unsigned int value, int pos);`<br/>Löscht in Variable `value` das Bit an Position `pos`. |
| Funktion `isBitSet` | `bool isBitSet(unsigned int value, int pos);`<br/>Liefert `true` zurück, wenn in Variable `value` das Bit an Position `pos` gesetzt ist, andernfalls `false`. |
| Funktion `isBitCleared` | `bool isBitCleared(unsigned int value, int pos);`<br/>Liefert `true` zurück, wenn in Variable `value` das Bit an Position `pos` nicht gesetzt ist, andernfalls `false`. |
| Funktion `countOnes` | `int countOnes(unsigned int value);`<br/>Liefert die Anzahl der Bits aus Variable `value` mit dem Wert 1 zurück. |
| Funktion `countZeros` | `int countZeros(unsigned int value);`<br/>Liefert die Anzahl der Bits aus Variable `value` mit dem Wert 0 zurück. |
| Funktion `powerOfTwo` | `void powerOfTwo();`<br/>Gibt die ersten 32 Zweier-Potenzen auf der Konsole aus. |
| Funktion `printIntAsBinary` | `void printIntAsBinary(unsigned int value);`<br/>Git die Binärdarstellung eines `unsigned int`-Zahlenwerts auf der Konsole aus. |

*Tabelle* 1. Exemplarische Funktionen zur Low-Level Programmierung in C/C++.

---

[Zurück](../../../Readme.md)

---
