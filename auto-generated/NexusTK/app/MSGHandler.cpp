// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// Source by-file UID: 0000LM
// Source by-file doc: by-file/MSGHandler.md
// UID:00008S | by-class/MSGHandler.md
class MSGHandler
{
public:
    MSGHandler();
    virtual ~MSGHandler();

    virtual int DispatchMessage();

private:
    MSGHandler* m_previousHandler;
};

// UID:0001CN | by-memory/0x00528d60-0x00528e55.MSGHandler.md
MSGHandler::MSGHandler()
    : m_previousHandler(g_pApplication->ExchangeMSGHandler(this))
{
}

MSGHandler::~MSGHandler()
{
    g_pApplication->ExchangeMSGHandler(m_previousHandler);
}

int MSGHandler::DispatchMessage()
{
    return m_previousHandler->DispatchMessage();
}
