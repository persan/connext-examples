
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

public class  PrimeNumberCalculationStatusTypeCode {
    public static final TypeCode VALUE = getTypeCode();

    private static TypeCode getTypeCode() {
        TypeCode tc = null;
        Annotations memberAnnotation;
        int i=0;
        EnumMember em[] = new EnumMember[3];

        int[] ordinals = PrimeNumberCalculationStatus.getOrdinals();
        for (i=0;i<3;i++) {
            PrimeNumberCalculationStatus ordinal = PrimeNumberCalculationStatus.valueOf(ordinals[i]);
            if (ordinal != null) {
                em[i]=new EnumMember(ordinal.toString(),ordinals[i]);
            } else {
                throw new IllegalStateException(
                    "Unexpected null ordinal creating the typecode");
            }
        }

        Annotations annotation = new Annotations();
        annotation.allowed_data_representation_mask(5);

        annotation.default_annotation(AnnotationParameterValue.ZERO_ENUM);
        tc = TypeCodeFactory.TheTypeCodeFactory.create_enum_tc("PrimeNumberCalculationStatus",ExtensibilityKind.EXTENSIBLE_EXTENSIBILITY,  em , annotation);        
        return tc;
    }
}

