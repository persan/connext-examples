

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from .idl 
using RTI Code Generator (rtiddsgen) version 4.0.0.
The rtiddsgen tool is part of the RTI Connext DDS distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the Code Generator User's Manual.
*/

package com.rti.example.primes.idl;

import com.rti.dds.util.Enum;
import com.rti.dds.cdr.CdrHelper;
import java.util.Arrays;
import java.io.ObjectStreamException;

public class PrimeNumberCalculationStatus  extends Enum {

    public static final PrimeNumberCalculationStatus REPLY_IN_PROGRESS = new PrimeNumberCalculationStatus("REPLY_IN_PROGRESS", 0);
    public static final int _REPLY_IN_PROGRESS = 0;
    public static final PrimeNumberCalculationStatus REPLY_COMPLETED = new PrimeNumberCalculationStatus("REPLY_COMPLETED", 1);
    public static final int _REPLY_COMPLETED = 1;
    public static final PrimeNumberCalculationStatus REPLY_ERROR = new PrimeNumberCalculationStatus("REPLY_ERROR", 2);
    public static final int _REPLY_ERROR = 2;
    public static PrimeNumberCalculationStatus valueOf(int ordinal) {
        switch(ordinal) {

            case 0: return PrimeNumberCalculationStatus.REPLY_IN_PROGRESS;
            case 1: return PrimeNumberCalculationStatus.REPLY_COMPLETED;
            case 2: return PrimeNumberCalculationStatus.REPLY_ERROR;

        }
        return null;
    }

    public static PrimeNumberCalculationStatus from_int(int __value) {
        return valueOf(__value);
    }

    public static int[] getOrdinals() {
        int i = 0;
        int[] values = new int[3];

        values[i] = REPLY_IN_PROGRESS.ordinal();
        i++;
        values[i] = REPLY_COMPLETED.ordinal();
        i++;
        values[i] = REPLY_ERROR.ordinal();
        i++;

        return values;
    }

    public int value() {
        return super.ordinal();
    }

    /**
    * Create a default instance
    */  
    public static PrimeNumberCalculationStatus create() {

        return valueOf(0);
    }

    /**
    * Print Method
    */     
    public java.lang.String toString(java.lang.String desc, int indent) {
        java.lang.StringBuffer strBuffer = new java.lang.StringBuffer();

        CdrHelper.printIndent(strBuffer, indent);

        if (desc != null) {
            strBuffer.append(desc).append(": ");
        }

        strBuffer.append(this);
        strBuffer.append("\n");              
        return strBuffer.toString();
    }

    private java.lang.Object readResolve() throws ObjectStreamException {
        return valueOf(ordinal());
    }

    private PrimeNumberCalculationStatus(java.lang.String name, int ordinal) {
        super(name, ordinal);
    }
}

