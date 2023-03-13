<h1 align="center"> LT - Langkah Terjauh</h1>
<br>

## Problem Description
<p align="justify">Due, seorang siswa SMA, sedang bersemangat belajar terkait pembuatan game.
Saat ini, ia baru saja selesai membuat program dan ingin mengetesnya. Sederhana
saja, ia hanya ingin mengetes apakah objek pada game yang dia buat bisa bergerak
sesuai dengan perintah yang diberikan. Karena hanya ingin bereksperimen, Due
membatasi fitur-fitur yang dibuat dengan rincian sebagai berikut:</p>
<ul>
<li type="1"><p align="justify">Objek hanya bisa bergerak maju dan mundur</p></li>
<li type="1"><p align="justify">Perintah disampaikan dengan mengetikkan string berisi karakter F(maju) dan B(mundur) dengan tiap perintah bernilai 1 langkah.</p></li>
<li type="1"><p align="justify">Objek berada di titik asal dan harus kembali ke titik asal setelah bergerak.
Contoh: Perintah FFFBFBBB dapat dijalankan karena kembali ke titik asal.</p></li>
<li type="1"><p align="justify">Tidak ada posisi di belakang titik asal.
Contoh: Perintah BF tidak dapat dijalankan karena ia mundur ketika berada
di titik asal.</p></li>
<li type="1"><p align="justify">Jika perintah tidak sesuai 4 aturan di atas (tidak valid), maka objek akan
mencari perintah valid terpanjang untuk dilaksanakan.
Contoh: Perintah BFBFFBBBB tidak valid sehingga objek hanya akan
menjalankan perintah ke-2 hingga ke-7, yaitu FBFFBB.</p></li>
</ul>
<p align="justify">Due tidak yakin dengan programnya sehingga ia akan menghitung banyaknya
langkah yang dijalankan objek dalam game. Selanjutnya, ia meminta bantuanmu
untuk menghitung banyak langkah yang seharusnya dijalankan berdasarkan aturan di
atas kemudian menyocokkannya. Bantulah Due mengetes programnya!</p>

## Input Format
<p align="justify">Baris pertama berisi bilangan bulat q, yaitu banyak perintah yang akan dites.
q baris berikutnya berisi string cmd, yaitu perintah game.
</p>

## Constrains
1 ≤ q ≤ 102
1 ≤ panjang string perintah ≤104

## Output Format
q baris berisi bilangan bulat jumlah
