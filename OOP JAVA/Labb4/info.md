Hur ska man gå till väga?

Projektet ska göras i två faser: (1) planering och sedan (2) implementering.
Planeringsfasen

Innan en enda rad kod skrivs bör ni noggrant planera strukturen av er lösning. Beskriv strukturen av din lösning i en textfil som heter design.txt.

Beskriv vilka abstraktioner ni kommer att använda er av. Med andra ord: vilka klasser du tänker implementera och hur de kommer att relatera till varandra. I model-view-controller mönstret är det naturligt att ha en klass för model, en för view och en för controller, men därutöver kanske det är bra att ha en klass för "ritade figurer".

Tips:  Alla ritade figurer har gemensamma egenskaper. Kunde samma kod implementera dessa gemensamma egenskaper?

Tips:  Designen är inte bindande. Om ni upptäcker att designen inte riktigt håller när ni skriver koden, ändra designen utifrån det ni lärt er.
Implementationsfasen

Vid handledning kommer handledare att börja med att be er visa och förklara er design.txt. Se till att den är klar innan ni ställer frågor angående implementationen.

I implementeringsfasen gäller det att programmera stegvis eftersom programmet är såpass komplicerat. Det går inte att skriva en hel lösning på en gång utan att provköra halvfärdiga versioner. Jag föreslår att ni delar upp programmeringen i separat delmål som går att provköras. Här är ett förslag på en lista av delmål:

    Få fram ett fönster som ser ut som ritprogrammet
    Koppla lyssnare till alla delar som bör ha lyssnare ActionListener, MouseListener, MouseMotionListener. (Man kan testa om de fungerar genom att skriva System.out.println-rader i lyssnarna.)
    Skissa klasserna för Model och för View. (Kom ihåg att View ska känna till Model, men inte Control. Model får inte ha referenser till View eller Control).
    Fyll i implementationen så att det går att rita svarta prickar.
    Fyll i så att det går att rita prickar av olika färger.
    Ge funktionalitet till undo knappen.
    ...

Med andra ord, lägg till delar stegvis. Kör programmet. Testa!

Obs:  Koden som implementerar save/load bör endast spara/ladda det som finns i Model. Implementering av save/load är del av årets föreläsning 12. Man kan också läsa om save/load här.

Tips: Lättast frågar man om filnamn med JOptionPane.showInputDialog("Give a file name:") så som vi gjorde i föreläsning 2.

Tips:  Musrörelser som att dra musen (som används för ritning av ovaler och rektanglar) görs med överskuggning av metoden mouseDragged i en MouseMotionListener.
