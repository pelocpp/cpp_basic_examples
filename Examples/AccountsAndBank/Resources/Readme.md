# Beispiel "Bankkonten und Bankinstitut"

Erstellen Sie eine Klasse `Account`, die das Guthaben eines Kontos verwaltet.
Zum Anlegen eines Kontos ben�tigt man (zur Vereinfachung der Aufgabenstellung) nur eine Kontonummer.
Die Klasse soll Methoden `deposit` zum Einzahlen und `withdrawal` zum Abheben besitzen.
Ausk�nfte �ber das Bankkonto k�nnen mit Hilfe der Eigenschaften `getNumber` (Kontonummer)
und `getBalance` (Kontostand) eingeholt werden.
F�r �berweisungen von einem Konto auf ein anderes gibt es die Methode `transfer`.

---

Noch ein *Hinweis*:
Der Quellcode im Repository zu dieser �bung ist bewu�t sehr elementar gehalten.
Oder um es anders zu formulieren: Viele der syntaktischen Neuerungen von C++ 11/14/17/20
sind bewu�t au�er Acht gelassen worden.
Es ist dem interessierten Leser �berlassen, diese Neuerungen einzuarbeiten.

---

Da das Abheben eines Betrags offensichtlich abh�ngig vom Kontotyp ist, bietet es sich an,
in der Klasse `Account` nur eine abstrakte Vorlage einer `withdrawal`-Methode festzulegen.
In speziellen Auspr�gungen eines Bankkontos wie etwa einem Girokonto oder einem Sparbuch kann man festlegen,
inwieweit beispielsweise das Konto beim Abheben �berzogen werden darf oder nicht.
Durch den R�ckgabewert `bool` teilt die `withdrawal`-Methode mit, 
ob eine Abhebung erfolgreich war oder nicht.

## Girokonten und Sparb�cher

Schreiben Sie drei weitere Klassen `CurrentAccount` (Girokonto), `StudentsAccount` (Konto ohne �berziehungsrahmen) und `DepositAccount` (Sparbuch), die Sie geeignet mit der Klasse `Account` in Beziehung setzen.
Die drei Klassen sollen folgende Eigenschaften aufweisen:

  * Klasse `CurrentAccount`</br>Ein Girokonto darf um ein Dispolimit �berzogen werden,
    das bei der Kontoer�ffnung festzulegen ist. Das Dispolimit ist als Eigenschaft der Klasse `CurrentAccount` zu realisieren
    und kann zu einem sp�teren Zeitpunkt auch angepasst werden.
    Der Einfachheit halber legen wir zu Grunde, dass f�r das �berziehen des Girokontos keine Zinsen zu entrichten sind.

  * Klasse `StudentsAccount`</br>Ein Konto f�r Sch�ler und Studenten verh�lt sich im Prinzip
    wie ein Girokonto. Der einzige Unterschied besteht darin, dass es keinen �berziehungsrahmen besitzt.

  * Klasse `DepositAccount`</br>Auf einem Sparkonto fallen f�r das eingezahlte Geld Zinsen an.
    Der Zinssatz des Sparkontos ist als Eigenschaft der Klasse `DepositAccount` darzustellen.
    Nach der Kontoer�ffnung kann der Zinssatz nicht mehr ge�ndert werden.
    F�r die Gutschrift der Zinsen auf dem Sparkonto bedarf es einer zus�tzlichen Methode `computeInterest`.
    Diese Methode besitzt als Parameter die Anzahl der Tage, f�r die die Zinsen gutzuschreiben sind.
    Die Zinsen sind nach der Formel

    <img src="Bankkonto_Zinssatz.png" width="250">

    zu berechnen.

## Bankinstitut

Erstellen Sie eine Klasse `Bank` (Bankinstitut), die eine unbestimmte Anzahl von Bankkonten verwaltet.
Das Bankinstitut besitzt Methoden, um ein Sparbuch, ein Girokonto und ein Konto ohne �berziehungsrahmen zu er�ffnen.
Besitzt ein Kunde ein Konto bei der Bank, kann er mit Hilfe der Kontonummer Einzahlungen, Abhebungen und �berweisungen t�tigen.
Zus�tzlich gew�hrt das Institut einen Einblick in die Liquidit�t des Hauses und gibt die H�he aller Einlagen mit der Eigenschaft 'totalBalance' preis.

Alle vorgestellten Klassen leiten sich (direkt oder indirekt) von der Basisklasse `IAccount` ab.
Diese Klasse stellt in Wirklichkeit eine Schnittstelle dar und definiert mit einer Reihe von
pure virtual methods das Aussehen aller abgeleiteten realen Klassen.

---

Die Programmausgabe studieren Sie an folgenden Codefragmenten:

*Beispiel*:

```cpp
CurrentAccount ca(123456, 1000);
ca.deposit(100);
ca.withdraw(40);
std::cout << ca << std::endl;

StudentsAccount sa(343434);
sa.deposit(50);
sa.withdraw(25);
std::cout << sa << std::endl;

DepositAccount da(654321, 4.0);
da.deposit(200);
da.withdraw(120);
da.computeInterest(31);
std::cout << da << std::endl;
```

*Ausgabe*:

```cpp
Testing accounts:
CurrentAccount [Nr. 123456]:
   Balance=60;
   Limit=1000.

StudentsAccount [Nr. 343434]:
   Balance=25;

DepositAccount [Nr. 654321]:
   Balance=80.2718;
   InterestRate=4.
```

---

*Beispiel*:

```cpp
std::cout << "Testing bank:" << std::endl;

Bank bank("Sparkasse");

int account = bank.createCurrentAccount(1000);
bank.deposit(account, 100);
bank.withdraw(account, 40);

int anotherAccount = bank.createDepositAccount(3.5);
bank.deposit(anotherAccount, 200);
bank.withdraw(anotherAccount, 80);
std::cout << bank << std::endl;

bank.transfer(anotherAccount, account, 80);
std::cout << bank << std::endl;

double totalBalance = bank.getTotalBalance();
std::cout << "Bank: Balance=" << bank.getTotalBalance() << std::endl;

bank.deleteAccount(account);
bank.deleteAccount(anotherAccount);

std::cout << "Bank: Balance=" << bank.getTotalBalance() << std::endl;
```

*Ausgabe*:

```cpp
Testing bank:
Bank 'Sparkasse':
CurrentAccount [Nr. 10001]:
   Balance=60;
   Limit=1000.
DepositAccount [Nr. 10002]:
   Balance=120;
   InterestRate=3.5.

Bank 'Sparkasse':
CurrentAccount [Nr. 10001]:
   Balance=140;
   Limit=1000.
DepositAccount [Nr. 10002]:
   Balance=40;
   InterestRate=3.5.

Bank: Balance=180
Bank: Balance=0
```

---

[Zur�ck](../../../Readme.md)
