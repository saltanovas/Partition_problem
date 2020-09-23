# Partition problem

<h3>Užduoties sąlyga:</h3>
<p>Duota N daiktų, kurių svoriai s1, s2,..., sn. Programa turi suskirstyti daiktus į dvi grupes taip, kad grupių svoriai būtų, kiek įmanoma, vienodesni. Vartotojas nurodo failą, iš kurio programa įveda daiktų svorius.</p>

<h3>Programos veikimo principas:</h3>
<ul>
<li>Dirbama su masyvais.</li>
<li>Duomenis susidedu į masyvą A, kurį išrikiuoju burbuliuko metodu. Kadangi didžiausi svoriai rezultatą įtakoja labiausiai, masyvas išrikiuojamas mažėjimo tvarka.</li>
<li>Funkcijoje pavadinimu atrinkti, kuri yra pagrindinė sprendimo funkcija, pirmiausiai surandama visų duomenų suma, kuri padalinama iš dviejų. Kodėl iš dviejų? Kadangi skaičius reikės išskirstyti į dvi grupes. Programoje ši suma pavadinta s.</li>
<li>Vėliau for cikle einama per visą masyvą A. Cikle yra viena if sąlyga, kuri ieško masyve A skaičių sumos, kuri yra artimiausia skaičiui s. Jei prie sumos (sum) pridėjus skaičių iš masyvo A vis dar gaunama mažiau už s arba tiek pat, įdedama į masyvą A1. Jei suma jau būna didesnė, įdedama į masyvą A2.</li>
<li>Pabaigoje išvedami masyvai A1 ir A2.</li>
</ul>

<h3>Kodėl pasirinktas būtent toks sprendimo būdas?</h3>
<p>Pereiti per visą masyvą užtrunka daug laiko, tačiau, mano manymu, tik tokiu būdu visuomet 100% gausime patį optimaliausią atsakymą. Iš pradžių buvo bandoma „paimti“ pirmus didžiausius skaičius, tuomet „persimesti“ į masyvo pabaigą, ir iš ten „paimti“ tiek, kiek reikia skaičių. Tokiu būdu algoritmas būtų greitesnis ir nereikėtų pereiti per visą masyvą. Tačiau tokiu būdu ne visuomet gaunamas pats optimaliausias atsakymas.</p>
