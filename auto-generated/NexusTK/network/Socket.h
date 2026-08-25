// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000NS
// Source by-file doc: by-file/Socket.md
// UID:0000DD | by-class/Socket.md | Completion:94 | Confidence:95
#pragma once

#include <winsock2.h>
#include "../util/Thread.h"

#include <windows.h>

class Socket : public Thread
{
public:
    Socket();
    virtual ~Socket();

    virtual void OnStart();
    virtual void OnIdle();
    virtual void HandleSocketCommand(int commandId, void *payload,
                                     unsigned long value);
    virtual int QueryTransportState(int query, unsigned char *outValue);
    virtual void HandleReceiveEvent(char eventCode);

    void PostConnectWithFallbackCommand(char transportMode,
                                        void *connectionParameter);
    void PostConnectCommand(char transportMode, void *connectionParameter);
    void PostResetConnectionCommand();
    HANDLE PostConnectionStatusQuery(bool *outConnected);
    void PostReconnectEndpointCommand(unsigned long hostAddress,
                                      unsigned short port);
    void PostPacketTransformTableCommand(unsigned char tableMode);
    void PostSocketReceiveCommand(void *receiveBuffer, int receiveSize);
    void QueueAndSendPacket(const void *packetData, short packetSize);
    void PostSocketModeByteCommand(unsigned char mode);
    void QueueTransportStringCommand(const char *text);
    void SendSingleByteCommand(unsigned char value);
    bool IsSocketConnectedState() const;
    void SetSocketSendDisabled(unsigned char disabled);
    void SetSocketConnectionFlag(unsigned char value);
    void QueueHandshakeBlock(unsigned int blockSize, const void *blockData);
    void QueueClientVersionStatusPacket();
    void BuildAndSendFriendNameListSync();
    unsigned char GetConnectionStatus() const;

private:
    void InitializeTransport(char transportMode, void *connectionParameter,
                             bool useFallback);
    void ResetConnectionState();
    void DispatchReceive();
    void SendEncodedPacket(const void *packetData,
                           unsigned short packetSize);
    void SendPacket(const char *text);
    void ConnectEndpoint(unsigned long hostAddress, unsigned short port,
                         bool useFallback);
    void CloseTransport();
    void ProcessQueuedReceiveBlock(void *block);
    void ProcessIncomingTransportData();
    void ReceiveNetworkData();
    int TransformFramePayload(const unsigned char *input, int inputLength,
                              unsigned char *output,
                              bool useAlternateKey);
    int BuildEncryptedPacket(const unsigned char *input, int inputLength,
                             unsigned char *output,
                             bool useAlternateKey);

    unsigned char *m_activeReadBuffer;                 // +0x00068
    unsigned char *m_alternateReadBuffer;              // +0x0006c
    unsigned char m_receiveBufferPrimary[60000];       // +0x00070
    unsigned char m_receiveBufferAlternate[60000];     // +0x0ead0
    int m_receiveByteCount;                            // +0x1d530
    int m_receiveCursor;                               // +0x1d534
    DWORD m_serialBaudRate;                            // +0x1d538
    HANDLE m_serialTransportHandle;                    // +0x1d53c
    unsigned char m_serialByteSize;                    // +0x1d540
    unsigned char m_serialParity;                      // +0x1d541
    unsigned char m_serialStopBits;                    // +0x1d542
    unsigned char m_serialFlowControl;                 // +0x1d543
    unsigned char m_serialReadActive;                  // +0x1d544
    unsigned char m_serialWriteActive;                 // +0x1d545
    unsigned char m_serialState[6];                    // +0x1d546
    OVERLAPPED m_serialReadOverlapped;                 // +0x1d54c
    OVERLAPPED m_serialWriteOverlapped;                // +0x1d560
    bool m_socketConnected;                            // +0x1d574
    SOCKET m_socket;                                   // +0x1d578
    unsigned char m_socketReadPending;                 // +0x1d57c
    unsigned char m_frameBuffer[40000];                // +0x1d57d
    int m_frameByteCount;                              // +0x271c0
    int m_frameCursor;                                 // +0x271c4
    unsigned char m_packetBuffer[40000];               // +0x271c8
    unsigned char m_encodedPacketBuffer[40000];        // +0x30e08
    unsigned char m_transportMode;                     // +0x3aa48
    unsigned char m_frameState[3];                     // +0x3aa49
    unsigned char m_protocolModeFlag;                  // +0x3aa4c
    unsigned char m_connectionFlag;                    // +0x3aa4d
    unsigned char m_sendDisabled;                      // +0x3aa4e
    unsigned char m_connectionStatus;                  // +0x3aa4f
    int m_connectionRetryDelay;                        // +0x3aa50
};

typedef char SocketSizeMustBe240212[
    sizeof(Socket) == 0x3aa54 ? 1 : -1];

// UID:0000Q5 | by-global/g_packetSender.md | Completion:90 | Confidence:91
extern Socket *g_packetSender;
