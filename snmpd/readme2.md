sudo apt-get install snmpd snmp snmp-mibs-downloader

sudo apt-get install libsnmp-dev libperl-dev

https://www.linuxidc.com/Linux/2016-03/129618.htm

sudo mv Test-MIB.my /usr/share/snmp/mibs

env MIBS=+Test-MIB mib2c Test-MIB::Time
