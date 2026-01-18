# CPROG
CPROG projekt

# INSTRUKTION

## Krav
- Användaren måste kontrollera att rätt flaggor sätts i Makefile för att spelet ska kompilera rätt enligt spelarens operativsystem
- Projektet använder sig av C++ och SDL3 vilket måste vara installerade på förhand för att kompilera spelet


## Instruktion för att bygga och testa
- Öppna terminalen och navigera till katalogen "Template" i projektets filstruktur.
- Kompilera spelet genom att köra kommandot "make"
- Kör spelet genom att skriva "./build/debug/play"


# TESTBESKRIVNING

## Beskrivning
Spelet är ett 2D-spel inspirerat av Space Invaders. Spelaren styr ett rymdskepp och försöker skjuta ner alla fiender innan alla liv tar slut. Spelaren har totalt fem liv.

## Testning
- Spelet förväntas öppna med en startskärm och spelaren ska kunna trycka enter för att påbörja spelet. 
- När spelaren trycker enter ska spelet ladda in spelaren med fem liv och ett visst antal fiender. 
- Spelaren ska kunna röra sig genom att trycka vänster- och högerknapp på sitt tangetbord och skuta fiender genom att trycka mellanslagstangenten.
- Målet med spelet är att skuta ner alla fiender innan spelaren förlorar alla fem liv. 
- När spelaren antingen vunnit eller förlorat kan spelaren trycka enter för att starta om spelet, eller klicka X i fönstrets hörn för att avsluta.




