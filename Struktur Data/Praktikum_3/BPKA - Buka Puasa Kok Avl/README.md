<h1 align="center">BPKA - Buka Puasa Kok Avl</h1>
<br>

## Problem Description
<p align="justify">Budi ditugaskan menyiapkan makanan untuk buka puasa Bersama. Ia di minta
untuk menaruh piring – piring berisi takjil di meja makan. Tetapi agar tidak bosan,
budi ber-ide untuk menyusun makanan secara aturan avl tree. Setelah itu ia akan
memberi tebak – tebakan pada Jenny saudaranya.</p>

<p align="justify">Jenny akan disuruh untuk memasukkan node X ke dalam AVL Tree ketika Budi
berkata "MASUKIN X". Budi dapat mengatakan itu berulang-ulang sampai Budi
berkata "HITUNG". kata "HITUNG" berarti Jenny disuruh untuk menjumlahkan setiap
kolom vertikal pada AVL Tree - Lalu mengkuadratkan setiap jumlah pada kolom, -
kemudian menjumlahkan seluruhnya seperti gambar berikut</p>

<p align="center">
<img align="center" src="https://github.com/jjchoNC/ctf-writeups/blob/main/UNITY%20CTF%202023/ES/Files/1.png" width="70%" height="auto" />
</p>

<b>Bantulan Jenny membuat program untuk menjawab pertannyaan Budi!<b>

## Input Format
- Input berupa MASUKKAN X , artinya memasukkan node X ke dalam AVL Tree. Dimana X adalah integer
- Input berupa HITUNG , menandakan akhir dari masukan dan diminta untuk menghitung sesuai yang diminta

## Constrains
- 1 <= X <= 1000
- jumlah baris MASUKKAN X ≤ 1000

## Output Format
<p align="justify">Output akan menghasilkan total dari penjumlahan dari setiap kuadrat dari jumlah per kolom
</p>
