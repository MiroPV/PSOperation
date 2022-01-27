Cred ca prea m-am complicat la inceput
cu Ex.1 ca mi-a creea ceva probleme la partea de .csv

Dar am reusit sa fac sa generez 2 fisiere .csv cu valori 
diferite. (de aia Generate1/2() ca aveam nevoie de timestamp-uri diferite)

Apoi iau string-ul din .csv si il transform intr-un aray de row/columns
Singura problema este ca inainte n-am lucrat cu vectori
iar acum a trebuit sa-l implementez local si by default, sizeof(vector) este de 24
si asta inseamna ca 2d array-ul meu nu poate avea mai mult de 24 valori.
Daca depaste 24 de valori, restul se pun automat 0. 

Poate ma voi intoarce la asta si o sa caut un workaround. 
Acum este facuta doar adunarea funtionala.