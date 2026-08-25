// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000JO
// Source by-file doc: by-file/FunctionObjects.md
// UID:0001WQ | by-type/by-template/FunctionObjectTemplates.md | Completion:88 | Confidence:90
#pragma once

#include "LObject.h"

class FunctionObject : public LObject
{
public:
    virtual ~FunctionObject() {}
    virtual void Invoke(unsigned long value) = 0;
    virtual unsigned int GetObjectSize() const = 0;
};

class FunctionObject0 : public LObject
{
public:
    virtual ~FunctionObject0() {}
    virtual void Invoke() = 0;
    virtual unsigned int GetObjectSize() const = 0;
};

template <class TArg>
class FunctionObjectT : public LObject
{
public:
    virtual ~FunctionObjectT() {}
    virtual void Invoke(TArg value) = 0;
    virtual unsigned int GetObjectSize() const = 0;
};

template <class TMember, class TObject>
class PlainMemberFunctionObject0 : public FunctionObject0
{
public:
    PlainMemberFunctionObject0(TMember callback, int thisAdjust, TObject *object)
        : m_callback(callback), m_thisAdjust(thisAdjust), m_object(object)
    {
    }

    virtual void Invoke()
    {
        TObject *target = reinterpret_cast<TObject *>(
            reinterpret_cast<char *>(m_object) + m_thisAdjust);
        (target->*m_callback)();
    }

    virtual unsigned int GetObjectSize() const
    {
        return sizeof(*this);
    }

private:
    TMember m_callback;
    int m_thisAdjust;
    TObject *m_object;
};

template <class TMember, class TObject, class TArg>
class PlainMemberFunctionObject : public FunctionObjectT<TArg>
{
public:
    PlainMemberFunctionObject(TMember callback, int thisAdjust, TObject *object)
        : m_callback(callback), m_thisAdjust(thisAdjust), m_object(object)
    {
    }

    virtual void Invoke(TArg value)
    {
        TObject *target = reinterpret_cast<TObject *>(
            reinterpret_cast<char *>(m_object) + m_thisAdjust);
        (target->*m_callback)(value);
    }

    virtual unsigned int GetObjectSize() const
    {
        return sizeof(*this);
    }

private:
    TMember m_callback;
    int m_thisAdjust;
    TObject *m_object;
};

template <class TMember, class TObject, class TArg>
class PlainMemberFunctionObjectT : public FunctionObjectT<TArg>
{
public:
    PlainMemberFunctionObjectT(TMember callback, int thisAdjust, TObject *object)
        : m_callback(callback), m_thisAdjust(thisAdjust), m_object(object)
    {
    }

    PlainMemberFunctionObjectT(TObject *object, TMember callback)
        : m_callback(callback), m_thisAdjust(0), m_object(object)
    {
    }

    virtual void Invoke(TArg value)
    {
        TObject *target = reinterpret_cast<TObject *>(
            reinterpret_cast<char *>(m_object) + m_thisAdjust);
        (target->*m_callback)(value);
    }

    virtual unsigned int GetObjectSize() const
    {
        return sizeof(*this);
    }

private:
    TMember m_callback;
    int m_thisAdjust;
    TObject *m_object;
};

template <class TMember, class TObject, class TArg0, class TArg1>
class DoubleParamMemberFunctionObject0 : public FunctionObject0
{
public:
    DoubleParamMemberFunctionObject0(TMember callback,
                                     int thisAdjust,
                                     TObject *object,
                                     TArg0 arg0,
                                     TArg1 arg1)
        : m_callback(callback),
          m_thisAdjust(thisAdjust),
          m_object(object),
          m_arg0(arg0),
          m_arg1(arg1)
    {
    }

    virtual void Invoke()
    {
        TObject *target = reinterpret_cast<TObject *>(
            reinterpret_cast<char *>(m_object) + m_thisAdjust);
        (target->*m_callback)(m_arg0, m_arg1);
    }

    virtual unsigned int GetObjectSize() const
    {
        return sizeof(*this);
    }

private:
    TMember m_callback;
    int m_thisAdjust;
    TObject *m_object;
    TArg0 m_arg0;
    TArg1 m_arg1;
};

template <class TMember, class TObject, class TInvokeArg, class TArg0, class TArg1>
class DoubleParamMemberFunctionObject : public FunctionObjectT<TInvokeArg>
{
public:
    DoubleParamMemberFunctionObject(TMember callback,
                                    int thisAdjust,
                                    TObject *object,
                                    TArg0 arg0,
                                    TArg1 arg1)
        : m_callback(callback),
          m_thisAdjust(thisAdjust),
          m_object(object),
          m_arg0(arg0),
          m_arg1(arg1)
    {
    }

    virtual void Invoke(TInvokeArg value)
    {
        TObject *target = reinterpret_cast<TObject *>(
            reinterpret_cast<char *>(m_object) + m_thisAdjust);
        (target->*m_callback)(value, m_arg0, m_arg1);
    }

    virtual unsigned int GetObjectSize() const
    {
        return sizeof(*this);
    }

private:
    TMember m_callback;
    int m_thisAdjust;
    TObject *m_object;
    TArg0 m_arg0;
    TArg1 m_arg1;
};
