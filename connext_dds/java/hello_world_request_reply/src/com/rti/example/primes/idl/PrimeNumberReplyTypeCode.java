
/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from .idl 
using RTI Code Generator (rtiddsgen) version 4.0.0.
The rtiddsgen tool is part of the RTI Connext DDS distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the Code Generator User's Manual.
*/

package com.rti.example.primes.idl;

import com.rti.dds.typecode.*;

public class  PrimeNumberReplyTypeCode {
    public static final TypeCode VALUE = getTypeCode();

    private static TypeCode getTypeCode() {
        TypeCode tc = null;
        int __i=0;
        StructMember sm[]=new StructMember[2];
        Annotations memberAnnotation;

        sm[__i] = new  StructMember("primes", false, (short)-1,  false, new TypeCode((com.rti.example.primes.idl.PRIME_SEQUENCE_MAX_LENGTH.VALUE), TypeCode.TC_LONG), 0, false);__i++;
        memberAnnotation = new Annotations();
        memberAnnotation.default_annotation(new AnnotationParameterValue(TCKind.TK_LONG, (int) (0)));
        memberAnnotation.min_annotation(AnnotationParameterValue.MIN_LONG);
        memberAnnotation.max_annotation(AnnotationParameterValue.MAX_LONG);
        sm[__i] = new  StructMember("status", false, (short)-1,  false, com.rti.example.primes.idl.PrimeNumberCalculationStatusTypeCode.VALUE, 1, false, memberAnnotation);__i++;

        Annotations annotation = new Annotations();
        annotation.allowed_data_representation_mask(5);

        tc = TypeCodeFactory.TheTypeCodeFactory.create_struct_tc("PrimeNumberReply",ExtensibilityKind.EXTENSIBLE_EXTENSIBILITY,  sm , annotation);        
        return tc;
    }
}

