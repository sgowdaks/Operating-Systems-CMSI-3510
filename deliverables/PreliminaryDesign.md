# Preliminary Design Document

Shivani Gowda and Jordyn Polk

## 1.1 – Description of modification/addition to Linux:

We want to introduce a new command freeport, that will identify a free networking port that is available.

## 1.2 – Rationale as to why this is a good idea, or what the good points of it are:

Netstat commands usually provides all the ports that are occupied, but freeport gives one port that is available. The freeport command will be helpful when launching web servers by letting the user know exactly which port is available.

## 1.3 – Preliminary list of [possible] Linux modules that will be modified/affected:

No commands will be modified.

## 1.4 – Preliminary list of any new modules that you will produce [or 'Not Applicable' if there are none]:

freep module - module that lists an available port
