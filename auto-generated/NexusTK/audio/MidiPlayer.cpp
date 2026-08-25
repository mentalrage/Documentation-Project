// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000LD
// Source by-file doc: by-file/MidiPlayer.md
// UID:00008A | by-class/MidiPlayer.md | Completion:89 | Confidence:92
#include "MidiPlayer.h"

// UID:0000T9 | by-global/MidiPlayerWinMMState.md | Completion:87 | Confidence:89
// MidiPlayerWinMMState is the documentation owner for the WinMM/static MIDI
// state family. It intentionally does not duplicate storage definitions here;
// exact data declarations belong to the child data pages that cover the concrete
// addresses, currently [UID:0002B1][0x0069b500-0x0069b870.MidiPlayerWinMMStateGlobals](by-memory/0x0069b500-0x0069b870.MidiPlayerWinMMStateGlobals.md) and [UID:0002B2][0x0069b870-0x0069b890.MidiSMFParserScratchGlobals](by-memory/0x0069b870-0x0069b890.MidiSMFParserScratchGlobals.md).
// UID:0002B1 | by-memory/0x0069b500-0x0069b870.MidiPlayerWinMMStateGlobals.md | Completion:91 | Confidence:93
static const unsigned int MIDI_RESET_SKIP_REOPEN = 0x00010000;
static const unsigned int MIDI_TRACK_PATH_CHARS = 260;
static const unsigned short MIDI_TRACK_NONE = (unsigned short)-1;
static const unsigned int MIDI_STREAM_BUFFER_BYTES = 0x400;

static const DWORD MIDI_STREAM_STATE_STOPPING = 100;
static const DWORD MIDI_STREAM_STATE_IDLE = 200;
static const DWORD MIDI_STREAM_STATE_FLUSHING = 300;

static const DWORD MIDI_TRACK_DONE = 0x00000001;
static const DWORD MIDI_TAG_MTHD = 0x6468544D;
static const DWORD MIDI_TAG_MTRK = 0x6B72544D;

static const BYTE MIDI_STATUS_CONTROL_CHANGE = 0xB0;
static const BYTE MIDI_STATUS_PROGRAM_CHANGE = 0xC0;
static const BYTE MIDI_STATUS_CHANNEL_PRESSURE = 0xD0;
static const BYTE MIDI_STATUS_SYSEX = 0xF0;
static const BYTE MIDI_STATUS_ESCAPE = 0xF7;
static const BYTE MIDI_STATUS_META = 0xFF;
static const BYTE MIDI_CONTROLLER_VOLUME = 7;
static const BYTE MIDI_META_END_OF_TRACK = 0x2F;
static const BYTE MIDI_META_TEMPO = 0x51;

enum MidiLoadResult {
    MIDI_LOAD_OK = 0,
    MIDI_LOAD_FAILED = 1
};

struct MidiTrackState {
    DWORD flags;
    DWORD trackLength;
    DWORD bufferedBytes;
    BYTE* buffer;
    BYTE* cursor;
    DWORD pendingTick;
    BYTE runningStatus;
    BYTE reservedStatus[3];
    DWORD trackStartOffset;
    DWORD sourceOffset;
    DWORD bytesRemaining;
};

struct MidiStreamWriteContext {
    LPSTR buffer;
    DWORD bufferLength;
    DWORD bytesRecorded;
    DWORD_PTR user;
    DWORD flags;
    MIDIHDR* next;
    DWORD_PTR reserved;
    DWORD offset;
    DWORD reservedWords[8];
    DWORD writeOffset;
    DWORD writeLimit;
    DWORD bytesWritten;
    DWORD lastEventTick;
    DWORD fullEventPending;
};

struct MidiStreamHeaderSlot {
    MIDIHDR header;
    DWORD writeOffset;
    DWORD writeLimit;
    DWORD bytesWritten;
    DWORD lastEventTick;
    DWORD fullEventPending;
};

struct MidiDocument {
    MidiDocument();

    int Load(const wchar_t* path);
    BOOL LoadFailed(const wchar_t* path);
    int FillStreamBuffer(BOOL resetState,
                         MidiStreamWriteContext* stream,
                         BOOL allowEndReplay);

    DWORD sourceSize;
    DWORD timeDivision;
    DWORD format;
    DWORD trackCount;
    MidiTrackState* tracks;
    DWORD datFileSource;
    DATFile datFile;
    HANDLE fileHandle;
    DWORD currentTick;
    DWORD allocatedPayloadCount;
    DWORD tempoTickCache;
    DWORD tempoScalePercent;
    DWORD tempoUSecPerQuarter;
};

static HMIDISTRM g_hMidiStream;
static UINT g_midiDeviceId;
static DWORD g_midiStreamState;
static DWORD g_midiRestartPending;
static BOOL g_midiAllowEndReplay;
static BOOL g_midiDocumentLoaded;
static BOOL g_midiStreamRunning;
static BOOL g_midiCallbackStreamOpen;
static BOOL g_midiHeadersPrepared;
static DWORD g_midiVolumeScale;
static MidiStreamHeaderSlot g_midiHeaders[2];
static DWORD g_midiChannelVolume[16];
static DWORD g_midiActiveHeaderIndex;
static DWORD g_midiPendingBufferCount;
static wchar_t g_midiCurrentPath[MIDI_TRACK_PATH_CHARS];
static HANDLE g_hMidiBufferEvent;
__declspec(align(8)) static MidiDocument g_midiDocumentState;
static DWORD g_midiEndOfStreamReached;

// UID:0002B2 | by-memory/0x0069b870-0x0069b890.MidiSMFParserScratchGlobals.md | Completion:89 | Confidence:92
struct MidiDocument;
struct MidiTrackState;
struct MidiStreamWriteContext;

struct MidiEvent {
    DWORD tick;
    BYTE status;
    BYTE data1;
    BYTE data2;
    BYTE reserved;
    DWORD payloadLength;
    BYTE* payload;
};

static const DWORD MIDI_FILL_AT_END = 0x00000001;
static const DWORD MIDI_FILL_PARSE_ERROR = 0x00000002;
static const DWORD MIDI_FILL_PENDING_EVENT = 0x00000004;

enum MidiFillResult {
    MIDI_FILL_OK = 0,
    MIDI_FILL_PARSE_FAILED = -101,
    MIDI_FILL_PREVIOUS_PARSE_FAILED = -102,
    MIDI_FILL_END_OF_STREAM = -103,
    MIDI_FILL_OUTPUT_FULL = -104,
    MIDI_FILL_UNSUPPORTED_EVENT = -105
};

static MidiTrackState* g_midiTrackScanCursor;
static MidiTrackState* g_midiSelectedTrack;
static DWORD g_midiFillState;
static DWORD g_midiSelectedTick;
static MidiEvent g_midiPendingEvent;

// UID:0000RM | by-global/g_pMidiPlayer.md | Completion:89 | Confidence:92
// g_pMidiPlayer is documented here as the process-wide MidiPlayer singleton.
// The concrete storage definition is emitted by the exact backing data page
// [UID:00029A][0x0067ab4c-0x0067ab50.g_pMidiPlayer](by-memory/0x0067ab4c-0x0067ab50.g_pMidiPlayer.md), so this symbol-level page must not duplicate it.
// UID:00029A | by-memory/0x0067ab4c-0x0067ab50.g_pMidiPlayer.md | Completion:88 | Confidence:91
MidiPlayer* g_pMidiPlayer = NULL;


// UID:00041H | by-memory/0x00525b10-0x00525b98.MidiReleaseStreamBuffers.md | Completion:88 | Confidence:90
static void ReleaseMidiStreamBuffers()
{
    if (g_midiHeadersPrepared != 0) {
        for (int i = 0; i < 2; ++i) {
            midiOutUnprepareHeader((HMIDIOUT)g_hMidiStream,
                                   &g_midiHeaders[i].header,
                                   sizeof(MIDIHDR));
        }
        g_midiHeadersPrepared = 0;
    }

    for (int i = 0; i < 2; ++i) {
        if (g_midiHeaders[i].header.lpData != NULL) {
            HGLOBAL block = GlobalHandle(g_midiHeaders[i].header.lpData);
            GlobalUnlock(block);
            block = GlobalHandle(g_midiHeaders[i].header.lpData);
            GlobalFree(block);
            g_midiHeaders[i].header.lpData = NULL;
        }
    }
}

// UID:0001CF | by-memory/0x00525b10-0x0052664b.MidiPlayerAndWinMMHelpers.md | Completion:88 | Confidence:90
// Emitted code for this mixed MidiPlayer WinMM aggregate is covered by exact child range pages.
// This parent range is an inventory/container and must not duplicate child output.

// UID:00041I | by-memory/0x00525ba0-0x00525bdf.MidiApplySingleChannelVolumeRaw.md | Completion:87 | Confidence:88
static void SendMidiChannelVolume(unsigned int channel, unsigned int volumeScale)
{
    if (g_midiStreamRunning == 0) {
        return;
    }

    DWORD scaled = (g_midiChannelVolume[channel] * volumeScale) / 1000;
    DWORD message = MIDI_STATUS_CONTROL_CHANGE |
                    channel |
                    (MIDI_CONTROLLER_VOLUME << 8) |
                    (scaled << 16);
    midiOutShortMsg((HMIDIOUT)g_hMidiStream, message);
}

// UID:0001CG | by-memory/0x00525be0-0x00525dbb.MidiStreamCallback.md | Completion:88 | Confidence:90
static void CALLBACK MidiStreamCallback(HMIDIOUT hMidiOut,
                                        UINT message,
                                        DWORD_PTR instance,
                                        DWORD_PTR param1,
                                        DWORD_PTR param2)
{
    (void)hMidiOut;
    (void)instance;
    (void)param2;

    if (message == MOM_POSITIONCB) {
        MIDIHDR* header = (MIDIHDR*)param1;
        BYTE* eventBase = (BYTE*)header->lpData + header->dwBytesRecorded;
        DWORD event = *(DWORD*)(eventBase + 8);
        BYTE controller = (BYTE)((event >> 8) & 0xff);

        if ((event & 0xf0) == MIDI_STATUS_CONTROL_CHANGE &&
            controller != 0x27 &&
            controller == MIDI_CONTROLLER_VOLUME) {
            unsigned int channel = event & 0x0f;
            unsigned int volume = (event >> 16) & 0x7f;

            g_midiChannelVolume[channel] = volume;
            if (g_midiStreamRunning != 0) {
                DWORD scaled = (g_midiVolumeScale * g_midiChannelVolume[channel]) / 1000;
                DWORD outgoing = MIDI_STATUS_CONTROL_CHANGE |
                                 channel |
                                 (MIDI_CONTROLLER_VOLUME << 8) |
                                 (scaled << 16);
                midiOutShortMsg((HMIDIOUT)g_hMidiStream, outgoing);
            }
        }
        return;
    }

    if (message != MOM_DONE) {
        return;
    }

    if (g_midiStreamState == MIDI_STREAM_STATE_IDLE) {
        return;
    }

    ++g_midiPendingBufferCount;

    if (g_midiStreamState == MIDI_STREAM_STATE_FLUSHING) {
        if (g_midiPendingBufferCount >= 2) {
            g_midiStreamState = MIDI_STREAM_STATE_IDLE;
            MidiPlayer_ResetStream(0);
            SetEvent(g_hMidiBufferEvent);
        }
        return;
    }

    if (g_midiStreamState == MIDI_STREAM_STATE_STOPPING) {
        if (g_midiPendingBufferCount >= 2) {
            g_midiStreamState = MIDI_STREAM_STATE_IDLE;
            SetEvent(g_hMidiBufferEvent);
        }
        return;
    }

    if (g_midiStreamRunning == 0 || g_midiPendingBufferCount == 0) {
        return;
    }

    MIDIHDR* header = &g_midiHeaders[g_midiActiveHeaderIndex].header;
    MidiStreamWriteContext* stream = (MidiStreamWriteContext*)header;
    stream->writeOffset = 0;
    stream->writeLimit = MIDI_STREAM_BUFFER_BYTES;
    stream->bytesWritten = 0;
    stream->lastEventTick = 0;
    stream->fullEventPending = 0;

    int fillResult = g_midiDocumentState.FillStreamBuffer(FALSE,
                                                          stream,
                                                          g_midiAllowEndReplay);
    if (fillResult != MIDI_FILL_OK) {
        if (fillResult == MIDI_FILL_END_OF_STREAM) {
            g_midiEndOfStreamReached = 1;
            g_midiStreamState = MIDI_STREAM_STATE_FLUSHING;
            return;
        }

        MidiDocumentRelease(&g_midiDocumentState);
        return;
    }

    header->dwBytesRecorded = stream->bytesWritten;
    if (midiStreamOut(g_hMidiStream, header, sizeof(MIDIHDR)) != MMSYSERR_NOERROR) {
        MidiDocumentRelease(&g_midiDocumentState);
        return;
    }

    g_midiActiveHeaderIndex = (g_midiActiveHeaderIndex + 1) % 2;
    --g_midiPendingBufferCount;
}

// UID:00041J | by-memory/0x00525dc0-0x00525f3d.MidiPlayerLifecycleMethods.md | Completion:88 | Confidence:90
MidiPlayer::MidiPlayer()
    : LObject(),
      m_playbackEnabled(g_pConfig->m_musicEnabled != 0),
      m_selectedTrackId(MIDI_TRACK_NONE)
{
    g_pMidiPlayer = this;
    g_midiDeviceId = MIDI_MAPPER;
    g_midiRestartPending = 0;
    g_midiAllowEndReplay = 1;
    g_midiDocumentLoaded = 0;
    g_midiStreamRunning = 0;
    g_midiHeadersPrepared = 0;
    g_midiCallbackStreamOpen = 0;
    g_midiVolumeScale = 500;
    g_hMidiBufferEvent = CreateEventW(NULL, FALSE, FALSE, L"Wait For Buffer Return");
}

MidiPlayer::~MidiPlayer()
{
    if (g_hMidiStream != NULL) {
        MidiPlayer_ResetStream(MIDI_RESET_SKIP_REOPEN);
    }

    ReleaseMidiStreamBuffers();

    if (g_hMidiStream != NULL) {
        midiStreamClose(g_hMidiStream);
        g_hMidiStream = NULL;
    }

    CloseHandle(g_hMidiBufferEvent);
    g_pMidiPlayer = NULL;
}

// UID:00041K | by-memory/0x00525f40-0x0052609a.MidiPlayerRawVolumeAndStreamLocalHelpers.md | Completion:88 | Confidence:90
static HANDLE CreateMidiBufferReturnEvent()
{
    g_hMidiBufferEvent = g_pfnCreateEventW(NULL, FALSE, FALSE, L"Wait For Buffer Return");
    return g_hMidiBufferEvent;
}

static bool OpenMidiStreamCallbackOnly()
{
    MMRESULT result = midiStreamOpen(&g_hMidiStream,
                                     &g_midiDeviceId,
                                     1,
                                     (DWORD_PTR)MidiStreamCallback,
                                     0,
                                     CALLBACK_FUNCTION);
    if (result != MMSYSERR_NOERROR) {
        return false;
    }

    g_midiCallbackStreamOpen = 1;
    return true;
}

static void CloseMidiStreamResources()
{
    if (g_hMidiStream != NULL) {
        MidiPlayer_ResetStream(MIDI_RESET_SKIP_REOPEN);
    }

    ReleaseMidiStreamBuffers();

    if (g_hMidiStream != NULL) {
        midiStreamClose(g_hMidiStream);
        g_hMidiStream = NULL;
    }

    CloseHandle(g_hMidiBufferEvent);
}

static void __stdcall ApplyMidiVolume(unsigned int volumeScale)
{
    if (g_midiStreamRunning == 0) {
        return;
    }

    for (unsigned int channel = 0; channel < 16; ++channel) {
        DWORD scaled = (g_midiChannelVolume[channel] * g_midiVolumeScale) / 1000;
        DWORD message = MIDI_STATUS_CONTROL_CHANGE |
                        channel |
                        (MIDI_CONTROLLER_VOLUME << 8) |
                        (scaled << 16);
        if (midiOutShortMsg((HMIDIOUT)g_hMidiStream, message) != MMSYSERR_NOERROR) {
            return;
        }
    }

    g_midiVolumeScale = volumeScale;
}

void MidiPlayer::IncreaseMidiVolume()
{
    if (m_playbackEnabled != 0 && g_midiVolumeScale <= 900) {
        ApplyMidiVolume(g_midiVolumeScale + 100);
    }
}

void MidiPlayer::DecreaseMidiVolume()
{
    if (m_playbackEnabled != 0 && g_midiVolumeScale >= 100) {
        ApplyMidiVolume(g_midiVolumeScale - 100);
    }
}

// UID:00041L | by-memory/0x005260a0-0x005260ff.MidiPlayerPlaybackToggleMethods.md | Completion:88 | Confidence:90
int MidiPlayer::IsPlaybackEnabled() const
{
    return m_playbackEnabled;
}

void MidiPlayer::EnableMidiPlayback()
{
    if (m_playbackEnabled == 0) {
        g_pConfig->m_musicEnabled = 1;
        m_playbackEnabled = 1;
    }
}

void MidiPlayer::DisableMidiPlayback()
{
    if (m_playbackEnabled == 1) {
        g_pConfig->m_musicEnabled = 0;
        m_selectedTrackId = MIDI_TRACK_NONE;
        MidiPlayer_ResetStream(0);
        m_playbackEnabled = 0;
    }
}

// UID:0001CH | by-memory/0x00526100-0x00526332.MidiPlayerTrackSelectionHelpers.md | Completion:88 | Confidence:89
static const unsigned short MIDI_TRACK_MAX = 12;

static void StartSelectedMidiFile(const wchar_t *path)
{
    wcscpy_s(g_midiCurrentPath, MIDI_TRACK_PATH_CHARS, path);

    if (g_midiDocumentLoaded != 0) {
        MidiPlayer_ResetStream(MIDI_RESET_SKIP_REOPEN);
    }

    if (MidiStreamOpenAndPrimeBuffers() == 0) {
        g_midiDocumentLoaded = 1;
    }

    if (g_midiRestartPending != 0) {
        midiStreamRestart(g_hMidiStream);
        g_midiRestartPending = 0;
        ApplyMidiVolume(g_midiVolumeScale);
        return;
    }

    if (g_midiStreamRunning != 0) {
        MidiPlayer_ResetStream(0);
    }

    if (g_midiDocumentLoaded == 0) {
        g_midiStreamRunning = 0;
    } else {
        g_midiStreamState = 0;
        if (midiStreamRestart(g_hMidiStream) == 0) {
            g_midiStreamRunning = 1;
            ApplyMidiVolume(g_midiVolumeScale);
            return;
        }
    }

    ApplyMidiVolume(g_midiVolumeScale);
}

void MidiPlayer::SelectTrack(unsigned short trackId)
{
    wchar_t configuredName[MIDI_TRACK_PATH_CHARS];
    wchar_t trackPath[MIDI_TRACK_PATH_CHARS];

    if (g_pConfig->m_midiEnabled == 0) {
        return;
    }
    if (m_playbackEnabled == 0) {
        return;
    }
    if (trackId > MIDI_TRACK_MAX) {
        return;
    }
    if (trackId == m_selectedTrackId) {
        return;
    }

    m_selectedTrackId = MIDI_TRACK_NONE;
    MidiPlayer_ResetStream(0);
    m_selectedTrackId = trackId;

    ConfigGetStringPreference(g_pConfig, (unsigned char)trackId, configuredName, MIDI_TRACK_PATH_CHARS);
    if (configuredName[0] != 0) {
        swprintf(trackPath, L"Midi\\%s", configuredName);
        g_midiAllowEndReplay = 0;
        StartSelectedMidiFile(trackPath);
    }

    if (g_midiStreamRunning == 0) {
        ConfigSetStringPreference(g_pConfig, (unsigned char)trackId, L"");
        swprintf(configuredName, L"%d.mid", trackId);
        g_midiAllowEndReplay = 1;
        StartSelectedMidiFile(configuredName);
    }
}

// UID:00041M | by-memory/0x00526340-0x00526350.MidiPlayerStopPlayback.md | Completion:87 | Confidence:89
void MidiPlayer::StopPlayback()
{
    m_selectedTrackId = MIDI_TRACK_NONE;
    MidiPlayer_ResetStream(0);
}

// UID:00041N | by-memory/0x00526350-0x00526452.MidiPlayerRawStreamControlHelpers.md | Completion:87 | Confidence:88
static void OpenSelectedMidiFileNoRestart(const wchar_t *path)
{
    wcscpy_s(g_midiCurrentPath, MIDI_TRACK_PATH_CHARS, path);

    if (g_midiDocumentLoaded != 0) {
        MidiPlayer_ResetStream(MIDI_RESET_SKIP_REOPEN);
    }

    if (MidiStreamOpenAndPrimeBuffers() == MMSYSERR_NOERROR) {
        g_midiDocumentLoaded = 1;
    }
}

static void ToggleMidiStreamPause()
{
    if (g_midiRestartPending != 0) {
        midiStreamRestart(g_hMidiStream);
        g_midiRestartPending = 0;
        return;
    }

    midiStreamPause(g_hMidiStream);
    g_midiRestartPending = 1;
}

static void RestartSelectedMidiStream()
{
    if (g_midiRestartPending != 0) {
        midiStreamRestart(g_hMidiStream);
        g_midiRestartPending = 0;
        return;
    }

    if (g_midiStreamRunning != 0) {
        MidiPlayer_ResetStream(0);
    }

    if (g_midiDocumentLoaded != 0) {
        g_midiStreamState = 0;
        if (midiStreamRestart(g_hMidiStream) == MMSYSERR_NOERROR) {
            g_midiStreamRunning = 1;
        }
        return;
    }

    g_midiStreamRunning = 0;
}

// UID:00041O | by-memory/0x00526460-0x00526569.MidiPlayerResetStream.md | Completion:88 | Confidence:90
static MMRESULT MidiPlayer_ResetStream(unsigned int flags)
{
    int documentLoaded = g_midiDocumentLoaded;
    int streamState = g_midiStreamState;

    if (g_midiDocumentLoaded == 0 &&
        g_midiStreamRunning == 0 &&
        g_midiStreamState == MIDI_STREAM_STATE_IDLE) {
        goto release_document;
    }

    g_midiRestartPending = 0;
    g_midiStreamRunning = 0;

    if (g_midiStreamState != MIDI_STREAM_STATE_IDLE) {
        if (g_midiStreamState != MIDI_STREAM_STATE_FLUSHING) {
            streamState = MIDI_STREAM_STATE_STOPPING;
        }
        g_midiStreamState = streamState;
    }

    MMRESULT result = midiStreamStop(g_hMidiStream);
    if (result != MMSYSERR_NOERROR) {
        return result;
    }

    result = midiOutReset((HMIDIOUT)g_hMidiStream);
    if (result != MMSYSERR_NOERROR) {
        return result;
    }

    result = WaitForSingleObject(g_hMidiBufferEvent, 2000);
    if (result != WAIT_TIMEOUT && g_midiStreamState != MIDI_STREAM_STATE_IDLE) {
        return result;
    }

    documentLoaded = g_midiDocumentLoaded;

release_document:
    g_midiStreamState = 0;

    if (documentLoaded != 0) {
        MidiDocumentRelease(&g_midiDocumentState);
        ReleaseMidiStreamBuffers();

        if (g_hMidiStream != NULL) {
            midiStreamClose(g_hMidiStream);
            g_hMidiStream = NULL;
        }

        g_midiDocumentLoaded = 0;
    }

    if ((flags & MIDI_RESET_SKIP_REOPEN) == 0) {
        result = MidiStreamOpenAndPrimeBuffers();
        if (result == MMSYSERR_NOERROR) {
            g_midiDocumentLoaded = 1;
        }
    } else {
        result = (MMRESULT)(flags >> 16);
    }

    return result;
}

// UID:0002BS | by-memory/0x00526650-0x005266a1.MidiExactReadHelper.md | Completion:88 | Confidence:91
static int MidiReadExact(MidiDocument* document, void* buffer, DWORD bytesToRead)
{
    DWORD bytesRead = bytesToRead;
    int readOk;

    if (document->datFileSource != 0) {
        readOk = document->datFile.Read(buffer, bytesToRead);
    } else {
        readOk = ReadFile(document->fileHandle, buffer, bytesToRead, &bytesRead, NULL);
    }

    return readOk == 0 || bytesRead != bytesToRead;
}

// UID:00023B | by-memory/0x00526650-0x005270d5.MidiFileReaderAndSMFParserHelpers.md | Completion:88 | Confidence:91
// This MIDI reader/parser range is an inventory aggregate. Exact child pages
// emit the source bodies for the helpers inside this island; the aggregate must
// not duplicate child output.

// UID:0002BT | by-memory/0x005266b0-0x00526784.MidiTrackBufferedByteReader.md | Completion:88 | Confidence:91
static int MidiReadTrackByte(MidiDocument* document, MidiTrackState* track, BYTE* value)
{
    DWORD sourcePosition;
    DWORD bytesToRead;
    DWORD bytesRead;
    int readOk;

    if (track->bufferedBytes == 0) {
        if (track->bytesRemaining == 0) {
            return 1;
        }

        track->cursor = track->buffer;

        if (document->datFileSource != 0) {
            document->datFile.Seek(track->sourceOffset, FILE_BEGIN);
            sourcePosition = document->datFile.Tell();
        } else {
            sourcePosition = SetFilePointer(document->fileHandle,
                                            track->sourceOffset,
                                            NULL,
                                            FILE_BEGIN);
        }

        if (sourcePosition == 0xFFFFFFFF) {
            return 1;
        }

        bytesToRead = track->bytesRemaining;
        if (bytesToRead > 0x400) {
            bytesToRead = 0x400;
        }

        track->bufferedBytes = bytesToRead;

        if (document->datFileSource != 0) {
            bytesRead = bytesToRead;
            readOk = document->datFile.Read(track->buffer, bytesToRead);
        } else {
            bytesRead = 0;
            readOk = ReadFile(document->fileHandle,
                              track->buffer,
                              bytesToRead,
                              &bytesRead,
                              NULL);
        }

        track->bytesRemaining -= bytesRead;
        track->bufferedBytes = bytesRead;
        track->sourceOffset = sourcePosition + bytesRead;

        if (readOk == 0 || bytesRead == 0) {
            return 1;
        }
    }

    *value = *track->cursor++;
    --track->bufferedBytes;
    return 0;
}

// UID:0002BU | by-memory/0x00526790-0x005269ea.MidiEventReader.md | Completion:88 | Confidence:91
static int MidiReadEvent(MidiDocument* document, MidiTrackState* track, MidiEvent* event)
{
    BYTE value;
    BYTE status;
    DWORD length;
    DWORD nextDelta;

    ZeroMemory(event, sizeof(*event));
    event->tick = track->pendingTick;

    if (MidiReadTrackByte(document, track, &value) != 0) {
        return 1;
    }

    if ((value & 0x80) != 0) {
        status = value;
        event->status = status;

        if (status < MIDI_STATUS_SYSEX) {
            track->runningStatus = status;
        }
    } else {
        status = (BYTE)track->runningStatus;
        if (status == 0) {
            return 1;
        }

        event->status = status;
        event->data1 = value;
    }

    if (status < MIDI_STATUS_SYSEX) {
        if ((value & 0x80) != 0) {
            if (MidiReadTrackByte(document, track, &event->data1) != 0) {
                return 1;
            }
        }

        if ((status & 0xF0) != MIDI_STATUS_PROGRAM_CHANGE &&
            (status & 0xF0) != MIDI_STATUS_CHANNEL_PRESSURE) {
            if (MidiReadTrackByte(document, track, &event->data2) != 0) {
                return 1;
            }
        }

        if (MidiReadVariableLength(document, track, &nextDelta) != 0) {
            return 1;
        }
        track->pendingTick += nextDelta;
        return 0;
    }

    if (status == MIDI_STATUS_SYSEX || status == MIDI_STATUS_ESCAPE) {
        if (MidiReadVariableLength(document, track, &length) != 0) {
            return 1;
        }

        event->payloadLength = length;
        if (length != 0) {
            event->payload = (BYTE*)malloc(length);
            if (event->payload == NULL) {
                return 1;
            }
            ++document->allocatedPayloadCount;

            for (DWORD i = 0; i < length; ++i) {
                if (MidiReadTrackByte(document, track, event->payload + i) != 0) {
                    return 1;
                }
            }
        }

        if (MidiReadVariableLength(document, track, &nextDelta) != 0) {
            return 1;
        }
        track->pendingTick += nextDelta;
        return 0;
    }

    if (status != MIDI_STATUS_META) {
        return 1;
    }

    if (MidiReadTrackByte(document, track, &event->data1) != 0) {
        return 1;
    }
    if (MidiReadVariableLength(document, track, &length) != 0) {
        return 1;
    }

    event->payloadLength = length;
    if (length != 0) {
        event->payload = (BYTE*)malloc(length);
        if (event->payload == NULL) {
            return 1;
        }
        ++document->allocatedPayloadCount;

        for (DWORD i = 0; i < length; ++i) {
            if (MidiReadTrackByte(document, track, event->payload + i) != 0) {
                return 1;
            }
        }
    }

    if (event->data1 == MIDI_META_END_OF_TRACK) {
        track->flags |= MIDI_TRACK_DONE;
        return 0;
    }

    if (MidiReadVariableLength(document, track, &nextDelta) != 0) {
        return 1;
    }
    track->pendingTick += nextDelta;
    return 0;
}

// UID:0002BV | by-memory/0x005269f0-0x00526ba8.MidiStreamEventEncoder.md | Completion:87 | Confidence:91
static DWORD MidiEventDelta(MidiStreamWriteContext* stream, const MidiEvent* event)
{
    DWORD delta = event->tick - stream->lastEventTick;
    stream->lastEventTick = event->tick;
    return delta;
}

static int MidiWriteShortStreamEvent(MidiStreamWriteContext* stream, DWORD tick, DWORD event)
{
    MIDIEVENT* outEvent;

    if (stream->writeOffset + sizeof(MIDIEVENT) > stream->writeLimit) {
        stream->fullEventPending = 1;
        return MIDI_FILL_OUTPUT_FULL;
    }

    outEvent = (MIDIEVENT*)(stream->buffer + stream->writeOffset);
    outEvent->dwDeltaTime = tick;
    outEvent->dwStreamID = 0;
    outEvent->dwEvent = event;

    stream->writeOffset += sizeof(MIDIEVENT);
    stream->bytesWritten += sizeof(MIDIEVENT);
    stream->fullEventPending = 0;
    return MIDI_FILL_OK;
}

static void MidiFreeEventPayload(MidiDocument* document, const MidiEvent* event)
{
    if (event->payload != NULL && document->allocatedPayloadCount != 0) {
        free(event->payload);
        --document->allocatedPayloadCount;
    }
}

static int MidiWriteStreamEvent(MidiDocument* document, const MidiEvent* event, MidiStreamWriteContext* stream)
{
    DWORD packed;
    DWORD tempo;
    int result;

    if (event->status < MIDI_STATUS_SYSEX) {
        packed = event->status | ((DWORD)event->data1 << 8) | ((DWORD)event->data2 << 16);

        if ((event->status & 0xF0) == MIDI_STATUS_CONTROL_CHANGE &&
            event->data1 == MIDI_CONTROLLER_VOLUME) {
            packed |= 0x40000000;
        }

        return MidiWriteShortStreamEvent(stream, MidiEventDelta(stream, event), packed);
    }

    if (event->status == MIDI_STATUS_SYSEX || event->status == MIDI_STATUS_ESCAPE) {
        MidiFreeEventPayload(document, event);
        return MIDI_FILL_OK;
    }

    if (event->status == MIDI_STATUS_META && event->data1 == MIDI_META_TEMPO) {
        if (event->payloadLength < 3 || event->payload == NULL) {
            MidiFreeEventPayload(document, event);
            return MIDI_FILL_UNSUPPORTED_EVENT;
        }

        tempo = ((DWORD)event->payload[0] << 16) |
                ((DWORD)event->payload[1] << 8) |
                (DWORD)event->payload[2];

        document->tempoUSecPerQuarter = tempo;
        document->tempoTickCache = event->tick;

        result = MidiWriteShortStreamEvent(
            stream,
            MidiEventDelta(stream, event),
            0x01000000 | (tempo & 0x00FFFFFF));

        MidiFreeEventPayload(document, event);
        return result;
    }

    MidiFreeEventPayload(document, event);
    return MIDI_FILL_UNSUPPORTED_EVENT;
}

// UID:0002BW | by-memory/0x00526bb0-0x00526cd9.MidiVariableLengthQuantityReader.md | Completion:88 | Confidence:91
static int MidiReadVariableLength(MidiDocument* document, MidiTrackState* track, DWORD* value)
{
    DWORD decoded;

    decoded = 0;

    if ((track->flags & MIDI_TRACK_DONE) != 0) {
        return 1;
    }

    for (;;) {
        BYTE byteValue;

        if (track->bufferedBytes == 0) {
            DWORD sourceOffset;
            DWORD bytesToRead;
            DWORD bytesRead;
            int readOk;

            if (track->bytesRemaining == 0) {
                track->flags |= MIDI_TRACK_DONE;
                return 1;
            }

            track->cursor = track->buffer;

            if (document->datFileSource != 0) {
                document->datFile.Seek(track->sourceOffset, FILE_BEGIN);
                sourceOffset = document->datFile.Tell();
            } else {
                sourceOffset = SetFilePointer(document->fileHandle, track->sourceOffset, NULL, FILE_BEGIN);
            }

            if (sourceOffset == INVALID_SET_FILE_POINTER) {
                return 1;
            }

            bytesToRead = track->bytesRemaining;
            if (bytesToRead > 0x400) {
                bytesToRead = 0x400;
            }

            bytesRead = bytesToRead;
            track->bufferedBytes = bytesToRead;

            if (document->datFileSource != 0) {
                readOk = document->datFile.Read(track->buffer, bytesToRead);
            } else {
                readOk = ReadFile(document->fileHandle, track->buffer, bytesToRead, &bytesRead, NULL);
            }

            track->bytesRemaining -= bytesRead;
            track->bufferedBytes = bytesRead;
            track->sourceOffset = sourceOffset + bytesRead;

            if (readOk == 0 || bytesRead == 0) {
                return 1;
            }
        }

        byteValue = *track->cursor++;
        --track->bufferedBytes;

        decoded = (decoded << 7) | (byteValue & 0x7F);
        if ((byteValue & 0x80) == 0) {
            *value = decoded;
            return 0;
        }
    }
}

// UID:0002BX | by-memory/0x00526ce0-0x00526d9a.MidiTrackBufferRefill.md | Completion:87 | Confidence:90
static int MidiRefillTrackBuffer(MidiDocument* document, MidiTrackState* track)
{
    DWORD sourcePosition;
    DWORD bytesToRead;
    DWORD bytesRead;
    int readOk;

    if (track->bytesRemaining == 0) {
        return 1;
    }

    track->cursor = track->buffer;

    if (document->datFileSource != 0) {
        document->datFile.Seek(track->sourceOffset, FILE_BEGIN);
        sourcePosition = document->datFile.Tell();
    } else {
        sourcePosition = SetFilePointer(document->fileHandle,
                                        track->sourceOffset,
                                        NULL,
                                        FILE_BEGIN);
    }

    if (sourcePosition == INVALID_SET_FILE_POINTER) {
        return 1;
    }

    bytesToRead = track->bytesRemaining;
    if (bytesToRead > 0x400) {
        bytesToRead = 0x400;
    }

    track->bufferedBytes = bytesToRead;

    if (document->datFileSource != 0) {
        bytesRead = bytesToRead;
        readOk = document->datFile.Read(track->buffer, bytesToRead);
    } else {
        bytesRead = bytesToRead;
        readOk = ReadFile(document->fileHandle,
                          track->buffer,
                          bytesToRead,
                          &bytesRead,
                          NULL);
    }

    track->bytesRemaining -= bytesRead;
    track->bufferedBytes = bytesRead;
    track->sourceOffset = sourcePosition + bytesRead;

    if (readOk == 0 || bytesRead == 0) {
        return 1;
    }

    return 0;
}

// UID:0002BY | by-memory/0x00526da0-0x00526f09.MidiTrackBufferPrimeReset.md | Completion:88 | Confidence:91
static void MidiPrimeTracks(MidiDocument* document)
{
    MidiTrackState* track;

    document->currentTick = 0;
    track = document->tracks;

    for (DWORD i = 0; i < document->trackCount; ++i, ++track) {
        DWORD bytesRead;
        DWORD firstRead;

        MidiSeekSource(document, (LONG)track->trackStartOffset, FILE_BEGIN);

        firstRead = track->trackLength;
        if (firstRead > 0x400) {
            firstRead = 0x400;
        }

        if (MidiReadRaw(document, track->buffer, firstRead, &bytesRead) == 0 ||
            bytesRead != firstRead) {
            return;
        }

        track->bytesRemaining = track->trackLength - bytesRead;
        track->bufferedBytes = bytesRead;
        track->sourceOffset = MidiSeekSource(document, 0, FILE_CURRENT);
        track->cursor = track->buffer;
        track->flags = 0;
        track->runningStatus = 0;
        track->pendingTick = 0;

        if (track->bufferedBytes != 0 || track->bytesRemaining != 0) {
            if (MidiReadVariableLength(document, track, &track->pendingTick) != 0) {
                return;
            }

            MidiSeekSource(document, (LONG)(track->trackStartOffset + track->trackLength), FILE_BEGIN);
        } else {
            track->flags = MIDI_TRACK_DONE;
        }
    }
}

// UID:0002BZ | by-memory/0x00526f10-0x00526f57.MidiSourceOpenHelper.md | Completion:88 | Confidence:90
static void MidiOpenSource(MidiDocument* document, const wchar_t* path)
{
    if (document->datFileSource != 0) {
        document->datFile.Open(path);
        document->fileHandle = INVALID_HANDLE_VALUE;
        return;
    }

    document->fileHandle = g_pfnCreateFileW(path,
                                            GENERIC_READ,
                                            FILE_SHARE_READ,
                                            NULL,
                                            OPEN_EXISTING,
                                            FILE_ATTRIBUTE_NORMAL,
                                            NULL);
}

// UID:0002C0 | by-memory/0x00526f60-0x00526f97.MidiSourceCloseHelper.md | Completion:87 | Confidence:90
static void MidiCloseSource(MidiDocument* document)
{
    if (document->datFileSource != 0) {
        if (document->datFile.IsOpen()) {
            document->datFile.Close();
        }
        return;
    }

    if (document->fileHandle != INVALID_HANDLE_VALUE) {
        CloseHandle(document->fileHandle);
        document->fileHandle = INVALID_HANDLE_VALUE;
    }
}

// UID:0002C1 | by-memory/0x00526fa0-0x00526ff6.MidiSourceSeekHelper.md | Completion:88 | Confidence:90
static DWORD MidiSeekSource(MidiDocument* document, LONG offset, DWORD origin)
{
    if (document->datFileSource != 0) {
        DWORD datOrigin = FILE_CURRENT;

        if (origin == FILE_BEGIN) {
            datOrigin = FILE_BEGIN;
        } else if (origin == FILE_END) {
            datOrigin = FILE_END;
        }

        document->datFile.Seek(offset, datOrigin);
        return document->datFile.Tell();
    }

    return SetFilePointer(document->fileHandle, offset, NULL, origin);
}

// UID:0002C2 | by-memory/0x00527000-0x00527039.MidiSourceRawReadHelper.md | Completion:88 | Confidence:91
static int MidiReadRaw(MidiDocument* document, void* buffer, DWORD bytesToRead, DWORD* bytesRead)
{
    if (document->datFileSource != 0) {
        *bytesRead = bytesToRead;
        return document->datFile.Read(buffer, bytesToRead);
    }

    return ReadFile(document->fileHandle, buffer, bytesToRead, bytesRead, NULL);
}

// UID:0002C3 | by-memory/0x00527040-0x00527078.MidiSourceSizeReadyHelper.md | Completion:88 | Confidence:90
static int MidiSourceIsReady(MidiDocument* document)
{
    if (document->datFileSource != 0) {
        return document->datFile.IsOpen() != 0;
    }

    if (document->fileHandle == INVALID_HANDLE_VALUE) {
        return 0;
    }

    document->sourceSize = GetFileSize(document->fileHandle, NULL);
    return document->sourceSize != INVALID_FILE_SIZE;
}

// UID:0002C4 | by-memory/0x00527080-0x005270b5.MidiReaderConstructorInit.md | Completion:90 | Confidence:92
MidiDocument::MidiDocument()
{
    datFileSource = 0;
    fileHandle = INVALID_HANDLE_VALUE;
    allocatedPayloadCount = 0;
    tempoScalePercent = 100;
}

// UID:0002C5 | by-memory/0x005270c0-0x005270d5.MidiDocumentLoadFailureWrapper.md | Completion:90 | Confidence:93
BOOL MidiDocument::LoadFailed(const wchar_t* path)
{
    return Load(path) == MIDI_LOAD_FAILED;
}

// UID:0001CI | by-memory/0x005270e0-0x005271a3.MidiDocumentRelease.md | Completion:88 | Confidence:90
static void MidiReleaseDocument(MidiDocument* document)
{
    if (document->datFileSource != 0) {
        if (document->datFile.IsOpen()) {
            document->datFile.Close();
        }
    } else if (document->fileHandle != INVALID_HANDLE_VALUE) {
        CloseHandle(document->fileHandle);
        document->fileHandle = INVALID_HANDLE_VALUE;
    }

    if (document->tracks != NULL) {
        for (DWORD i = 0; i < document->trackCount; ++i) {
            MidiTrackState* track = document->tracks + i;
            if (track->buffer != NULL) {
                HGLOBAL block = GlobalHandle(track->buffer);
                GlobalUnlock(block);
                block = GlobalHandle(track->buffer);
                GlobalFree(block);
            }
        }

        HGLOBAL table = GlobalHandle(document->tracks);
        GlobalUnlock(table);
        table = GlobalHandle(document->tracks);
        GlobalFree(table);
        document->tracks = NULL;
    }
}

// UID:0002C6 | by-memory/0x005271b0-0x005273a0.MidiStreamBufferFillHelper.md | Completion:92 | Confidence:94
int MidiDocument::FillStreamBuffer(BOOL resetState, MidiStreamWriteContext* stream, BOOL allowEndReplay)
{
    stream->bytesWritten = 0;

    DWORD state;
    if (resetState) {
        state = 0;
        g_midiFillState = 0;
        ZeroMemory(&g_midiPendingEvent, sizeof(g_midiPendingEvent));
        g_midiSelectedTrack = NULL;
        g_midiTrackScanCursor = NULL;
    } else {
        state = g_midiFillState;
    }

    if ((state & MIDI_FILL_AT_END) != 0) {
        if (!allowEndReplay) {
            return MIDI_FILL_END_OF_STREAM;
        }

        MidiPrimeTracks(this);
        g_midiFillState = 0;
    } else if ((state & MIDI_FILL_PARSE_ERROR) != 0) {
        return MIDI_FILL_PREVIOUS_PARSE_FAILED;
    } else if ((state & MIDI_FILL_PENDING_EVENT) != 0) {
        g_midiFillState = state ^ MIDI_FILL_PENDING_EVENT;

        if (g_midiPendingEvent.status == MIDI_STATUS_META &&
            g_midiPendingEvent.data1 == MIDI_META_END_OF_TRACK) {
            if (allocatedPayloadCount != 0) {
                free(g_midiPendingEvent.payload);
                --allocatedPayloadCount;
            }
        } else if (MidiWriteStreamEvent(this, &g_midiPendingEvent, stream) == MIDI_FILL_OUTPUT_FULL) {
            g_midiFillState |= MIDI_FILL_PENDING_EVENT;
            return MIDI_FILL_OK;
        }
    }

    for (;;) {
        DWORD remaining = trackCount;
        MidiTrackState* cursor = tracks;
        MidiTrackState* selected = NULL;
        DWORD selectedTick = 0xFFFFFFFF;

        g_midiSelectedTrack = NULL;
        g_midiSelectedTick = 0xFFFFFFFF;
        g_midiTrackScanCursor = cursor;

        while (remaining != 0) {
            if ((cursor->flags & MIDI_TRACK_DONE) == 0 &&
                cursor->pendingTick < selectedTick) {
                selected = cursor;
                selectedTick = cursor->pendingTick;
            }
            ++cursor;
            --remaining;
        }

        g_midiTrackScanCursor = cursor;
        g_midiSelectedTick = selectedTick;
        g_midiSelectedTrack = selected;

        if (selected == NULL) {
            g_midiFillState |= MIDI_FILL_AT_END;
            return MIDI_FILL_OK;
        }

        if (MidiReadEvent(this, selected, &g_midiPendingEvent) != 0) {
            g_midiFillState |= MIDI_FILL_PARSE_ERROR;
            return MIDI_FILL_PARSE_FAILED;
        }

        if (g_midiPendingEvent.status == MIDI_STATUS_META &&
            g_midiPendingEvent.data1 == MIDI_META_END_OF_TRACK) {
            if (allocatedPayloadCount != 0) {
                free(g_midiPendingEvent.payload);
                --allocatedPayloadCount;
            }
        } else if (MidiWriteStreamEvent(this, &g_midiPendingEvent, stream) == MIDI_FILL_OUTPUT_FULL) {
            g_midiFillState |= MIDI_FILL_PENDING_EVENT;
            return MIDI_FILL_OK;
        }
    }
}

// UID:0002C7 | by-memory/0x005273a0-0x005277bb.MidiSMFDocumentLoadHelper.md | Completion:93 | Confidence:94
int MidiDocument::Load(const wchar_t* path)
{
    struct MidiHeaderFields {
        WORD format;
        WORD trackCount;
        WORD division;
    } header;

    DWORD tag;
    DWORD headerLength;
    DWORD bytesRead;
    DWORD i;
    HGLOBAL tableHandle;

    currentTick = 0;
    timeDivision = 0;
    format = 0;
    trackCount = 0;
    sourceSize = 0;
    tracks = NULL;

    MidiOpenSource(this, path);
    if (!MidiSourceIsReady(this)) {
        goto load_failed;
    }

    if (MidiReadRaw(this, &tag, sizeof(tag), &bytesRead) == 0 ||
        bytesRead != sizeof(tag) || tag != MIDI_TAG_MTHD) {
        goto load_failed;
    }

    if (MidiReadExact(this, &headerLength, sizeof(headerLength)) != 0) {
        goto load_failed;
    }

    headerLength = ((headerLength & 0x000000FF) << 24) |
                   ((headerLength & 0x0000FF00) << 8) |
                   ((headerLength & 0x00FF0000) >> 8) |
                   ((headerLength & 0xFF000000) >> 24);

    if (headerLength < sizeof(header) ||
        MidiReadExact(this, &header, headerLength) != 0) {
        goto load_failed;
    }

    format = (WORD)((header.format << 8) | (header.format >> 8));
    trackCount = (WORD)((header.trackCount << 8) | (header.trackCount >> 8));
    timeDivision = (WORD)((header.division << 8) | (header.division >> 8));

    tableHandle = GlobalAlloc(GMEM_ZEROINIT,
                              sizeof(MidiTrackState) * trackCount);
    tracks = (MidiTrackState*)GlobalLock(tableHandle);
    if (tracks == NULL) {
        goto load_failed;
    }

    for (i = 0; i < trackCount; ++i) {
        MidiTrackState* track = tracks + i;

        HGLOBAL bufferHandle = GlobalAlloc(GHND, MIDI_STREAM_BUFFER_BYTES);
        track->buffer = (BYTE*)GlobalLock(bufferHandle);
        if (track->buffer == NULL ||
            MidiReadExact(this, &tag, sizeof(tag)) != 0 ||
            tag != MIDI_TAG_MTRK ||
            MidiReadExact(this, &headerLength, sizeof(headerLength)) != 0) {
            goto load_failed;
        }

        headerLength = ((headerLength & 0x000000FF) << 24) |
                       ((headerLength & 0x0000FF00) << 8) |
                       ((headerLength & 0x00FF0000) >> 8) |
                       ((headerLength & 0xFF000000) >> 24);

        track->trackLength = headerLength;
        track->trackStartOffset = MidiSeekSource(this, 0, FILE_CURRENT);

        DWORD firstRead = track->trackLength;
        if (firstRead > MIDI_STREAM_BUFFER_BYTES) {
            firstRead = MIDI_STREAM_BUFFER_BYTES;
        }

        if (MidiReadRaw(this, track->buffer, firstRead, &bytesRead) == 0 ||
            bytesRead != firstRead) {
            goto load_failed;
        }

        track->bytesRemaining = track->trackLength - bytesRead;
        track->bufferedBytes = bytesRead;
        track->sourceOffset = MidiSeekSource(this, 0, FILE_CURRENT);
        track->cursor = track->buffer;
        track->flags = 0;
        track->runningStatus = 0;
        track->pendingTick = 0;

        if (track->bufferedBytes != 0 || track->bytesRemaining != 0) {
            if (MidiReadVariableLength(this, track, &track->pendingTick) != 0) {
                goto load_failed;
            }
        } else {
            track->flags = MIDI_TRACK_DONE;
        }

        MidiSeekSource(this,
                       (LONG)(track->trackStartOffset + track->trackLength),
                       FILE_BEGIN);
    }

    return MIDI_LOAD_OK;

load_failed:
    MidiReleaseDocument(this);
    return MIDI_LOAD_FAILED;
}

// UID:00025W | by-memory/0x0061fafc-0x0061fb70.MidiPlayerReadOnlyData.md | Completion:88 | Confidence:92
// MidiPlayer read-only data is source-declared/generated-binary output. The
// vtable rebuilds from the MidiPlayer class declaration; the event name,
// track-selection formats, and default channel-volume vector emit through
// their MidiPlayer.cpp consumer helpers/state declarations. This page must not
// hand-port raw vtable, RTTI, literal, or pooled .rdata bytes.

// UID:0001CE | by-memory\0x00525920-0x00525b0d.MidiStreamOpenAndPrimeBuffers.md | Completion:87 | Confidence:90 | Empty Emitter Marker
