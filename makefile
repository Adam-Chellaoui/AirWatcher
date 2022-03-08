#Makefile du Main
CFLAGS = -Wall -ansi -pedantic -std=c++11
# -DMAP permet de définir MAP et donc afficher les traces.
# -Wall permet d'afficher toutes les alertes.
# -ansi désactive les fonctionnalités incompatible avec ISO C90.
# -pedantic est utilisé avec -ansi pour forcer à n'utiliser uniquement ce qui est reconnu par l'ISO C90.
# -std=c++11 force le compilateur à utiliser C++11

main: main.o Date.o Measurement.o Provider.o Attribute.o Cleaner.o Sensor.o User.o ReadCSV.o Model.o View.o Controller.o
	g++ -o main main.o Date.o Measurement.o Provider.o Attribute.o Cleaner.o Sensor.o User.o ReadCSV.o Model.o View.o Controller.o

main.o: main.cpp
	g++ -c $(CFLAGS) main.cpp

Date.o: Metier/Date.cpp
	g++ -c $(CFLAGS) Metier/Date.cpp

Measurement.o: Metier/Measurement.cpp
	g++ -c $(CFLAGS) Metier/Measurement.cpp

Provider.o: Metier/Provider.cpp
	g++ -c $(CFLAGS) Metier/Provider.cpp

Attribute.o: Metier/Attribute.cpp
	g++ -c $(CFLAGS) Metier/Attribute.cpp

Cleaner.o: Metier/Cleaner.cpp
	g++ -c $(CFLAGS) Metier/Cleaner.cpp

Sensor.o: Metier/Sensor.cpp
	g++ -c $(CFLAGS) Metier/Sensor.cpp

User.o: Metier/User.cpp
	g++ -c $(CFLAGS) Metier/User.cpp

ReadCSV.o: ReadCSV.cpp
	g++ -c $(CFLAGS) util/ReadCSV.cpp

Model.o: Model.cpp
	g++ -c $(CFLAGS) model/Model.cpp

View.o: View.cpp
	g++ -c $(CFLAGS) view/View.cpp

Controller.o: Controller.cpp
	g++ -c $(CFLAGS) controller/Controller.cpp

