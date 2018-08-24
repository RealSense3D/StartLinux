## install asn1c

- sudo apt-get install asn1c

## asn.1 file

- rectangle.asn1

## encode

- cd encode
- asn1c -fskeletons-copy -fnative-types rectangle.asn1
- mv converter-sample.c converter-sample.c-
- gcc -I. -o rencode *.c

---

#### note:

when compile the converter-sample.c, there maybe is a problem, as the below:

> converter-sample.o:(.data+0x0): undefined reference to `asn_DEF_PDU'
> collect2: error: ld returned 1 exit status
> make: *** [progname] Error 1

But fortunately, the 'converter-sample.c' commented: 

> To compile with your own ASN.1 type, please redefine the PDU as shown:
> cc -DPDU=MyCustomType -o myDecoder.o -c converter-sample.c

or

modify the file at line 26, as:

> /* Convert "Type" defined by -DPDU into "asn_DEF_Type" */
> #define	ASN_DEF_PDU(t)	asn_DEF_Rectangle //xx t

---

## decode

- cd ../decode
- asn1c -fskeletons-copy -fnative-types rectangle.asn1
- mv converter-sample.c converter-sample.c-
- gcc -I. -o rdecode *.c


## test

- cd ../encode
- ./rencode ../rectangle.dat
- cd ../decode
- ./rdecode ../rectangle.dat
