

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from .idl 
using RTI Code Generator (rtiddsgen) version 4.0.0.
The rtiddsgen tool is part of the RTI Connext DDS distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the Code Generator User's Manual.
*/

package com.rti.example.primes.idl;

import com.rti.dds.infrastructure.*;
import com.rti.dds.infrastructure.Copyable;
import java.io.Serializable;
import com.rti.dds.cdr.CdrHelper;

public class PrimeNumberReply   implements Copyable, Serializable{

    public IntSeq primes =  new IntSeq((com.rti.example.primes.idl.PRIME_SEQUENCE_MAX_LENGTH.VALUE));
    public com.rti.example.primes.idl.PrimeNumberCalculationStatus status = (com.rti.example.primes.idl.PrimeNumberCalculationStatus)com.rti.example.primes.idl.PrimeNumberCalculationStatus.valueOf(0);

    public PrimeNumberReply() {

    }
    public PrimeNumberReply (PrimeNumberReply other) {

        this();
        copy_from(other);
    }

    public static java.lang.Object create() {

        PrimeNumberReply self;
        self = new  PrimeNumberReply();
        self.clear();
        return self;

    }

    public void clear() {

        if (primes != null) {
            primes.clear();
        }
        status = com.rti.example.primes.idl.PrimeNumberCalculationStatus.valueOf(0);
    }

    @Override
    public boolean equals(java.lang.Object o) {

        if (o == null) {
            return false;
        }        

        if(getClass() != o.getClass()) {
            return false;
        }

        PrimeNumberReply otherObj = (PrimeNumberReply)o;

        if(!this.primes.equals(otherObj.primes)) {
            return false;
        }
        if(!this.status.equals(otherObj.status)) {
            return false;
        }

        return true;
    }

    @Override
    public int hashCode() {
        final int __prime = 31;
        int __result = 1;
        __result = __prime * __result + primes.hashCode(); 
        __result = __prime * __result + status.hashCode(); 
        return __result;
    }

    /**
    * This is the implementation of the <code>Copyable</code> interface.
    * This method will perform a deep copy of <code>src</code>
    * This method could be placed into <code>PrimeNumberReplyTypeSupport</code>
    * rather than here by using the <code>-noCopyable</code> option
    * to rtiddsgen.
    * 
    * @param src The Object which contains the data to be copied.
    * @return Returns <code>this</code>.
    * @exception NullPointerException If <code>src</code> is null.
    * @exception ClassCastException If <code>src</code> is not the 
    * same type as <code>this</code>.
    * @see com.rti.dds.infrastructure.Copyable#copy_from(java.lang.Object)
    */
    public java.lang.Object copy_from(java.lang.Object src) {

        PrimeNumberReply typedSrc = (PrimeNumberReply) src;
        PrimeNumberReply typedDst = this;

        typedDst.primes.copy_from(typedSrc.primes);
        typedDst.status = (com.rti.example.primes.idl.PrimeNumberCalculationStatus) typedDst.status.copy_from(typedSrc.status);

        return this;
    }

    @Override
    public java.lang.String toString(){
        return toString("", 0);
    }

    public java.lang.String toString(java.lang.String desc, int indent) {
        java.lang.StringBuffer strBuffer = new java.lang.StringBuffer();

        if (desc != null) {
            CdrHelper.printIndent(strBuffer, indent);
            strBuffer.append(desc).append(":\n");
        }

        CdrHelper.printIndent(strBuffer, indent+1);
        strBuffer.append("primes: ");
        for(int i__ = 0; i__ < this.primes.size(); ++i__) {
            if (i__!=0) strBuffer.append(", ");
            strBuffer.append(this.primes.get(i__));
        }
        strBuffer.append("\n"); 
        strBuffer.append(this.status.toString("status ", indent+1));

        return strBuffer.toString();
    }

}
