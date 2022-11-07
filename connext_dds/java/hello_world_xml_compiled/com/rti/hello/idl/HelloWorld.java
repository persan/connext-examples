

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from .idl 
using RTI Code Generator (rtiddsgen) version 4.0.0.
The rtiddsgen tool is part of the RTI Connext DDS distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the Code Generator User's Manual.
*/

package com.rti.hello.idl;

import com.rti.dds.infrastructure.*;
import com.rti.dds.infrastructure.Copyable;
import java.io.Serializable;
import com.rti.dds.cdr.CdrHelper;

public class HelloWorld   implements Copyable, Serializable{

    public String sender= (String)""; /* maximum length = ((com.rti.hello.idl.MAX_NAME_LEN.VALUE)) */
    public String message= (String)""; /* maximum length = ((com.rti.hello.idl.MAX_MSG_LEN.VALUE)) */
    public int count = (int)0;

    public HelloWorld() {

    }
    public HelloWorld (HelloWorld other) {

        this();
        copy_from(other);
    }

    public static java.lang.Object create() {

        HelloWorld self;
        self = new  HelloWorld();
        self.clear();
        return self;

    }

    public void clear() {

        sender = (String)"";
        message = (String)"";
        count = (int)0;
    }

    @Override
    public boolean equals(java.lang.Object o) {

        if (o == null) {
            return false;
        }        

        if(getClass() != o.getClass()) {
            return false;
        }

        HelloWorld otherObj = (HelloWorld)o;

        if(!this.sender.equals(otherObj.sender)) {
            return false;
        }
        if(!this.message.equals(otherObj.message)) {
            return false;
        }
        if(this.count != otherObj.count) {
            return false;
        }

        return true;
    }

    @Override
    public int hashCode() {
        final int __prime = 31;
        int __result = 1;
        __result = __prime * __result + sender.hashCode(); 
        __result = __prime * __result + message.hashCode(); 
        __result = __prime * __result + (int)count;
        return __result;
    }

    /**
    * This is the implementation of the <code>Copyable</code> interface.
    * This method will perform a deep copy of <code>src</code>
    * This method could be placed into <code>HelloWorldTypeSupport</code>
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

        HelloWorld typedSrc = (HelloWorld) src;
        HelloWorld typedDst = this;

        typedDst.sender = typedSrc.sender;
        typedDst.message = typedSrc.message;
        typedDst.count = typedSrc.count;

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
        strBuffer.append("sender: ").append(this.sender).append("\n");  
        CdrHelper.printIndent(strBuffer, indent+1);        
        strBuffer.append("message: ").append(this.message).append("\n");  
        CdrHelper.printIndent(strBuffer, indent+1);        
        strBuffer.append("count: ").append(this.count).append("\n");  

        return strBuffer.toString();
    }

}
