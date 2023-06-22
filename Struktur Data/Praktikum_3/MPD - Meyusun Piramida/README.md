<h1 align="center">MPD - Menyusun Piramida</h1>
<br>

## Problem Description
<p align="justify">Dalam rangka memahami konsep balance pada AVL tree, Due dan temannya
mencoba membuat permainan Menyusun Piramida. Permainan ini dapat dilakukan
oleh lebih dari 1 pemain, dimana tiap pemain bergantian memberikan sebuah angka
yang nantinya akan disusun ke dalam sebuah piramida berbentuk BST. Pemain akan
mendapat poin jika angka yang ia berikan dapat menjaga sifat balance dari tree yang
sudah terbentuk.</p>
<p align="justify">Sebagai pembuat permainan, Due ingin dapat mengecek angka yang diberikan
temannya secara otomatis. Oleh karena itu, ia meminta bantuan kamu untuk membuat
program yang dapat mengecek apakah angka yang akan diinsert dapat menjaga
balance dari tree yang telah terbentuk atau tidak</p>
<b>Note: definisi balance berdasarkan AVL tree, yaitu selisih tinggi node kiri dan
kanan tidak boleh lebih dari 1.
</b>

## Input Format
- Baris pertama berisi bilangan bulat n, yaitu banyak angka pada tree
- Baris kedua berisi n bilangan bulat yang merupakan nilai setiap node pada tree *(urutan sudah dipastikan membentuk tree yang balance)
- Baris ketiga berisi bilangan bulat x, yaitu angka yang akan diinsert


## Constrains
- 1 ≤ n ≤ 20
- Nilai node integer        

## Output Format
<p align="justify">“Tree tetap balance”, jika angka yang diberikan (x) dapat menjaga balance dari
tree</p>
<p align="justify">“Tree tidak balance”, jika angka yang diberikan (x) dapat membuat tree tidak
balance
</p>
