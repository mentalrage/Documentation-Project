** TARGET-REPORT-UID:0000HO **
** AUTHOR-AGENT-ID:B009 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0000HO BackPane Empty-Emitter Family Source-Quality Report

## Finalized Report / Current Recommendation

- Current recommendation: accept [UID:0000HO] `by-file/BackPane.md` as the source-file owner/emitter for the BackPane and BackGroundPane family and clear all current `auto-generated/NexusTK/map/BackPane.cpp` empty markers with either first-draft formal C++ or exact no-code/no-duplicate comments.
- Final disposition: implemented after supervisor acceptance. Do not leave any listed empty marker for future C++; every current empty marker has a target-specific action below and an applied proof in the ledger/checklist.
- Required action: update the file, class, method, global-storage, shared-literal, and RTTI-support docs listed in the checklist; then run scoped validators and inspect regenerated `auto-generated/NexusTK/map/BackPane.cpp`.
- Confidence: high for ownership, ranges, data storage, and source/no-code split; medium-high for final source spelling of BackGroundPane method/field names and help packet method names because original symbols/dispatch entries remain unrecovered.

## Implementation Callback Status

- Implemented on 2026-07-01 by Agent-B009 after supervisor acceptance.
- Edited target/support docs: `by-file/BackPane.md`; `by-class/BackGroundPane.md`; `by-memory/0x00467510-0x0046782f.BackGroundPaneCoreMethods.md`; `by-class/BackPane.md`; `by-memory/0x004679c0-0x00467b2d.BackPaneActivatePaintAndDestructor.md`; `by-memory/0x004eaf20-0x004eb044.BackPaneHelpPacketDisplayV1.md`; `by-memory/0x004ede80-0x004edfa4.BackPaneHelpPacketDisplayV2.md`; `by-memory/0x004ef510-0x004ef62e.BackPaneHelpPacketDisplayV3.md`; `by-memory/0x00610fd0-0x00610fe8.SharedNpal5PaletteResourceString.md`; `by-memory/0x00612f38-0x00612f3c.BackGroundPaneRttiLocatorPointer.md`; `by-memory/0x0067a740-0x0067a744.g_pBackPane.md`; `by-memory/0x0067ab7c-0x0067ab80.g_pBackGroundPane.md`.
- Generated verification: `auto-generated/NexusTK/map/BackPane.cpp` refreshed by validator command `000000003782` at `2026-07-01T07:30:18-04:00`; inspection found the accepted UID sections and no old "No reconstruction"/empty-marker text for the eleven audited targets.
- Lease status: B009 lease attempt covered all 12 edited by-* docs; post-validator release reported no active lease for each path, and `tools/leaser/Agents/Agent-B009/current_leases.md` contains no active B009 rows.

## Target

- Target UID: [UID:0000HO]
- Target path: `by-file/BackPane.md`
- Source queue/report row: `auto-generated/-ag-research-tracker.md` / `## Files With Empty Emitters`
- Generated output checked: `auto-generated/NexusTK/map/BackPane.cpp`, refreshed by validator command `000000003690` at `2026-07-01T07:01:49-04:00`, currently 13 emitters, 2 filled, 11 empty, 15.4%.
- Current target state: `COMPLETION:86`, `CONFIDENCE:88`, `CANONICAL_OWNER:FILE`, source path `NexusTK/map/`, file page already owns `BackPane`, `BackGroundPane`, [UID:00030M] constructor/destructor, [UID:000161] `GetBounds`, help helpers, singleton storage, and resource/literal support.

## Current Empty Markers Audited

| UID | Path | Current state | Report disposition |
| --- | --- | --- | --- |
| 00000R | `by-class/BackGroundPane.md` | class formal C++ blank | add first-draft class declaration and evidence notes |
| 00030L | `by-memory/0x00467510-0x0046782f.BackGroundPaneCoreMethods.md` | method cluster formal C++ blank | add first-draft constructor/destructor/callback/paint/accessor C++ plus no-handwritten wrapper comments |
| 00000S | `by-class/BackPane.md` | class formal C++ blank | add first-draft class declaration and method evidence |
| 00030N | `by-memory/0x004679c0-0x00467b2d.BackPaneActivatePaintAndDestructor.md` | method cluster formal C++ blank | add first-draft `OnActivate`, `OnPaint`, clear helper, and no-handwritten deleting-destructor comments |
| 00018K | `by-memory/0x004eaf20-0x004eb044.BackPaneHelpPacketDisplayV1.md` | helper formal C++ blank | add first-draft help-packet helper body, preserving zero-xref caveat |
| 00018L | `by-memory/0x004ede80-0x004edfa4.BackPaneHelpPacketDisplayV2.md` | helper formal C++ blank | add first-draft V2 helper body, preserving zero-xref caveat |
| 00018M | `by-memory/0x004ef510-0x004ef62e.BackPaneHelpPacketDisplayV3.md` | helper formal C++ blank | add first-draft V3 byte-id helper body, preserving zero-xref caveat; fix stale `Nested:-4` to `0` |
| 00044W | `by-memory/0x00610fd0-0x00610fe8.SharedNpal5PaletteResourceString.md` | shared literal formal C++ blank | add exact no-standalone/no-duplicate comment |
| 000488 | `by-memory/0x00612f38-0x00612f3c.BackGroundPaneRttiLocatorPointer.md` | compiler RTTI pointer formal C++ blank | add exact compiler-generated no-code comment |
| 00028J | `by-memory/0x0067a740-0x0067a744.g_pBackPane.md` | singleton storage formal C++ blank | add source global definition `BackPane *g_pBackPane = NULL;` |
| 0002VV | `by-memory/0x0067ab7c-0x0067ab80.g_pBackGroundPane.md` | singleton storage formal C++ blank | add source global definition `BackGroundPane *g_pBackGroundPane = NULL;`, correcting stale `ff ff ff ff` wording to current zero bytes |

## Inference Research Guidance Check

The current B-agent workflow rejects old "blank until 95/95" and "missing exact original names" blockers when the binary shape, source owner, range, and behavior are strong enough for first-draft source. I treated raw IDA names, historical generated names, and old coverage rows as evidence only, not source truth. Direct IDA facts below are separated from documentation evidence and source-facing inference.

Wave2/Wave3 material was encountered only as stale alias history (`byte_66DA97`, `dword_67A7CC`, `dword_67A764`, `dword_67A7C8`). Current canonical names used here are `g_useEpfAssets`, `g_pScreenPane`/screen cursor context where applicable, `g_activeMapPane`, and `g_pConfig`; stale aliases should be retained only as evidence/search aliases.

## Evidence Checked

- Live IDA MCP session: `supervisor_resume_20260629`.
- MCP health: call `101` `server_health` returned `status:ok`, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, module `NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready, strings count `2067`.
- MCP function lookup: call `102` checked the exact goal addresses. Code starts and sizes: `0x467510 0x9b`, `0x4675b0 0x29`, `0x4675e0 0x80`, `0x467690 0x55`, accessors `0x467740/750` size `0x7`, setters `0x467760/770/780/790` size `0x8`, clear helper `0x4677a0 0xb`, deleting destructor `0x4677d0 0x5f`, `0x4679c0 0x1d`, `0x4679e0 0x68`, clear helper `0x467a50 0xb`, deleting destructor `0x467a80 0xad`, help helpers `0x4eaf20 0x124`, `0x4ede80 0x124`, `0x4ef510 0x11e`. Data addresses `0x0067a740`, `0x0067ab7c`, `0x00612f38`, and `0x00610fd0` are not functions.
- MCP decompiles: calls `210`-`228` decompiled every in-scope function exactly.
- MCP bytes/ints: calls `310` and `311` read current bytes/values. `g_pBackPane` and `g_pBackGroundPane` are both `00 00 00 00` / value `0`. RTTI pointer bytes are `7c 22 64 00` / value `0x0064227c`. `0x00610fd0` decodes UTF-16 `NPAL5.PAL`; `0x0061304c` decodes UTF-16 `FRAME.PAL`.
- MCP xrefs: calls `320`-`324` checked capped xrefs for singleton slots, RTTI pointer, and palette strings; call `330` checked help-helper reachability.
- Docs checked: target file, `by-class/BackPane.md`, `by-class/BackGroundPane.md`, all 11 empty-marker docs, populated [UID:00030M] and [UID:000161], aggregate [UID:0000YY], resource page `by-resource/backpane-background-resources.md`, generated `auto-generated/NexusTK/map/BackPane.cpp`, and old executed-report/search material.
- Validators: not run; report-only assignment.

## IDA MCP Facts

- [UID:00030L] `BackGroundPane` constructor calls `Pane(0)`, publishes `g_pBackGroundPane` through the adjusted `this+0xf8` guard path, installs vtable views `0x00612f3c`, `0x00612f88`, `0x00612fb8`, initializes `EPFTileContext` at `this+0x138`, and zeroes the two readiness bytes at `this+0x160/+0x161`.
- [UID:00030L] ordinary destructor and deleting destructor both restore BackGroundPane vtables, clear `g_pBackGroundPane`, call base `Pane` cleanup, and the deleting wrapper conditionally frees the block. The clear helper at `0x4677a0` is exactly `g_pBackGroundPane = 0`.
- [UID:00030L] packet/state callback reads event byte from `*(a2+12)`, writes `g_pBackGroundPane->+0x161` from `*(float *)(g_activeMapPane+0x3dc) > 0.80000001`, handles event codes `4`, `8`, `0xb`, `0x15`, and `0x26`, gates invalidation on `g_pConfig` and `sub_5055D0(g_activeMapPane)`, and returns `0`.
- [UID:00030L] `OnPaint` draws the EPF tile only when bytes `+0x160` and `+0x161` are both true; otherwise it clears pane mode byte `+0x70`, calls the palette/state helper with `128`, and fills/invalidates through the inherited draw callback.
- [UID:00030N] `BackPane::OnActivate` returns `1` and, when `g_useEpfAssets != 1`, calls the screen/cursor helper `sub_5573F0(g_pScreenPane, 0, 0)`.
- [UID:00030N] `BackPane::OnPaint` calls `BackPane::GetBounds` and `sub_4B9980(m_frameTileContext, this+0x108, this+0x44, 0, paletteName, 0)`, selecting `FRAME.PAL` when `g_useEpfAssets == 1` and `NPAL5.PAL` otherwise.
- [UID:00030N] clear helper at `0x467a50` is exactly `g_pBackPane = 0`; scalar deleting destructor at `0x467a80` duplicates the ordinary destructor body from [UID:00030M] and conditionally frees memory.
- [UID:00018K] and [UID:00018L] read a big-endian/packet word at `packet+1`, mask it with `0x3fff`, read text length at `packet+3`, accept non-empty text up to `1023` bytes, convert `packet+5` with `MultiByteToWideChar(0,0, ..., 1023)`, null-terminate with compiler range-check guard, get BackPane bounds, close `g_pSimpleHelpPane` if present, allocate `252` bytes, and construct `SimpleHelpPane` with centered x coordinate, masked id/position, and timeout `10000`.
- [UID:00018M] has the same popup path, except id/position is the one-byte `packet+2` value via `std::_Narrow_char_traits<char,int>::to_char_type`; length still comes from `packet+3`.
- `xrefs_to` on the three help helpers still returns zero refs. This is a dispatch-table/reachability caveat, not a no-code blocker: each body is a normal `thiscall` BackPane helper and passes the BackPane receiver to `GetBounds` and `SimpleHelpPane`.
- [UID:00028J] `g_pBackPane`: `xrefs_to` reports `106` refs, including target lifecycle writes at `0x467878`, `0x46787f`, `0x46793d`, `0x467a50`, and `0x467ad4`; current bytes are zero.
- [UID:0002VV] `g_pBackGroundPane`: `xrefs_to` reports six refs, all inside BackGroundPane lifecycle/callback code (`0x467556`, `0x46755d`, `0x4675ca`, `0x467601`, `0x4677a0`, `0x4677f0`); current bytes are zero, contradicting the stale `ff ff ff ff` storage row.
- [UID:00044W] `NPAL5.PAL`: bytes decode exact UTF-16 `NPAL5.PAL`, four xrefs, including BackPane paint at `0x467a20`; other refs at `0x46169d`, `0x5b9519`, and `0x5be938` prove it is shared, not BackPane-private storage.
- [UID:000488] `0x00612f38` is not a function, has no xrefs, and contains dword `0x0064227c` immediately before the BackGroundPane vtable island at `0x00612f3c`; this is compiler RTTI/COL pointer data generated from the class, not source-authored storage.

## Heuristic / Inference Reanalysis And Validation

- Stale "95/95 blank-C++ gate" language on `BackPane`, `BackGroundPane`, and child pages is rejected. Current workflow supports first-draft formal C++ when exact range/body/owner/source-placement evidence is strong.
- Missing original method names for help helpers no longer justifies blank C++. The bodies are decompilable, source-shaped, class-owned, and tied to existing generated owner names. The report keeps names descriptive: `ShowHelpFromPacket`, `ShowHelpFromPacketV2`, and `ShowHelpFromPacketV3`.
- Missing final BackGroundPane field names no longer justifies blank C++. Field roles are exact: tile context `+0x138`, readiness bytes `+0x160/+0x161`, inherited bounds `+0x44`, tile target `+0x148`, label/resource name area `+0x118`, and mode byte `+0x70`. Use descriptive first-draft names and preserve offset evidence.
- The `g_pBackGroundPane` static-byte contradiction is resolved by current MCP: use zero initialization, not the old `ff ff ff ff` claim.
- `NPAL5.PAL` is not eligible for a BackPane-owned standalone declaration because xrefs prove shared source-use literal pooling; use a no-duplicate comment.
- The RTTI pointer is not eligible for source declaration because it is compiler-generated metadata immediately before vtable data, with no source body or xrefs; use a no-code compiler metadata comment.

## First-Draft C++ Recommendation

These are exact formal `RECONSTRUCTION_CPP CODE` insertion texts for the accepted implementation callback. Names marked as inferred should be explained in prose in the destination docs.

### [UID:00000R] `by-class/BackGroundPane.md`

```cpp
class BackGroundPane : public Pane
{
public:
    BackGroundPane();
    virtual ~BackGroundPane();

    char HandleBackgroundPacketEvent(const PacketEvent *event);
    virtual void OnPaint();

    bool IsBackgroundFrameReady() const;
    bool IsMapReadyForBackground() const;
    void MarkBackgroundFrameReady();
    void ClearBackgroundFrameReady();
    void MarkMapReadyForBackground();
    void ClearMapReadyForBackground();

private:
    EPFTileContext m_backgroundTileContext;
    bool m_backgroundFrameReady;
    bool m_mapReadyForBackground;
};
```

### [UID:00030L] `by-memory/0x00467510-0x0046782f.BackGroundPaneCoreMethods.md`

```cpp
BackGroundPane::BackGroundPane()
    : Pane(0)
{
    g_pBackGroundPane = this;
    m_backgroundTileContext.Initialize();
    m_backgroundFrameReady = false;
    m_mapReadyForBackground = false;
}

BackGroundPane::~BackGroundPane()
{
    g_pBackGroundPane = NULL;
}

char BackGroundPane::HandleBackgroundPacketEvent(const PacketEvent *event)
{
    const unsigned char eventCode = *event->payload;

    g_pBackGroundPane->m_mapReadyForBackground =
        g_activeMapPane->GetBackgroundBlendAmount() > 0.8f;

    switch (eventCode)
    {
    case 0x04:
    case 0x08:
    case 0x0b:
    case 0x15:
    case 0x26:
        if (g_pConfig->IsBackgroundRefreshEnabled() &&
            g_activeMapPane->CanRefreshBackground())
        {
            InvalidateRect(&m_backgroundBounds);
        }
        break;

    default:
        return 0;
    }

    return 0;
}

void BackGroundPane::OnPaint()
{
    if (m_backgroundFrameReady && m_mapReadyForBackground)
    {
        DrawTileContext(&m_backgroundTileContext,
                        &m_backgroundTileTarget,
                        &m_bounds,
                        0,
                        m_backgroundPaletteName,
                        0);
        return;
    }

    SetMode(0);
    SetDrawColor(128);
    FillRect(&m_bounds);
}

bool BackGroundPane::IsBackgroundFrameReady() const
{
    return m_backgroundFrameReady;
}

bool BackGroundPane::IsMapReadyForBackground() const
{
    return m_mapReadyForBackground;
}

void BackGroundPane::MarkBackgroundFrameReady()
{
    m_backgroundFrameReady = true;
}

void BackGroundPane::ClearBackgroundFrameReady()
{
    m_backgroundFrameReady = false;
}

void BackGroundPane::MarkMapReadyForBackground()
{
    m_mapReadyForBackground = true;
}

void BackGroundPane::ClearMapReadyForBackground()
{
    m_mapReadyForBackground = false;
}

void ClearBackGroundPane()
{
    g_pBackGroundPane = NULL;
}

// The adjustor thunks at 0x004677ab-0x004677c1 and the scalar deleting
// destructor at 0x004677d0-0x0046782f are compiler-generated from
// BackGroundPane::~BackGroundPane(); do not hand-author separate source.
```

### [UID:00000S] `by-class/BackPane.md`

```cpp
class BackPane : public Pane
{
public:
    explicit BackPane(const wchar_t *frameResourceName);
    virtual ~BackPane();

    virtual bool OnActivate(int activateCode);
    virtual void OnPaint();
    RectBounds *GetBounds(RectBounds *outBounds) const;

    void ShowHelpFromPacket(const unsigned char *packet);
    void ShowHelpFromPacketV2(const unsigned char *packet);
    void ShowHelpFromPacketV3(const unsigned char *packet);

private:
    EPFTileContext m_frameTileContext;
    int m_frameWidth;
    int m_frameHeight;
};
```

### [UID:00030N] `by-memory/0x004679c0-0x00467b2d.BackPaneActivatePaintAndDestructor.md`

```cpp
bool BackPane::OnActivate(int activateCode)
{
    if (g_useEpfAssets != 1)
        g_pScreenPane->SetCursor(0, 0);

    return true;
}

void BackPane::OnPaint()
{
    RectBounds bounds;
    GetBounds(&bounds);

    const wchar_t *paletteName = (g_useEpfAssets == 1)
        ? L"FRAME.PAL"
        : L"NPAL5.PAL";

    DrawTileContext(&m_frameTileContext,
                    &m_frameTileTarget,
                    &m_bounds,
                    0,
                    paletteName,
                    0);
}

void ClearBackPane()
{
    g_pBackPane = NULL;
}

// The adjustor thunks at 0x00467a5b-0x00467a71 and the scalar deleting
// destructor at 0x00467a80-0x00467b2d are compiler-generated from
// BackPane::~BackPane(); the ordinary destructor body is emitted by
// [UID:00030M].
```

### [UID:00018K] `by-memory/0x004eaf20-0x004eb044.BackPaneHelpPacketDisplayV1.md`

```cpp
void BackPane::ShowHelpFromPacket(const unsigned char *packet)
{
    const int helpId = ReadPacketWord(packet + 1) & 0x3fff;
    const unsigned short textLength = ReadPacketWord(packet + 3);

    if (textLength == 0 || textLength > 1023)
        return;

    wchar_t text[1024];
    const int converted = MultiByteToWideChar(0, 0,
                                              reinterpret_cast<const char *>(packet + 5),
                                              textLength,
                                              text,
                                              1023);
    text[converted] = L'\0';

    RectBounds bounds;
    GetBounds(&bounds);

    if (g_pSimpleHelpPane != NULL)
        g_pSimpleHelpPane->Close(true);

    new SimpleHelpPane(text,
                       this,
                       (bounds.left + bounds.right) / 2,
                       helpId,
                       10000);
}
```

### [UID:00018L] `by-memory/0x004ede80-0x004edfa4.BackPaneHelpPacketDisplayV2.md`

```cpp
void BackPane::ShowHelpFromPacketV2(const unsigned char *packet)
{
    const int helpId = ReadPacketWord(packet + 1) & 0x3fff;
    const unsigned short textLength = ReadPacketWord(packet + 3);

    if (textLength == 0 || textLength > 1023)
        return;

    wchar_t text[1024];
    const int converted = MultiByteToWideChar(0, 0,
                                              reinterpret_cast<const char *>(packet + 5),
                                              textLength,
                                              text,
                                              1023);
    text[converted] = L'\0';

    RectBounds bounds;
    GetBounds(&bounds);

    if (g_pSimpleHelpPane != NULL)
        g_pSimpleHelpPane->Close(true);

    new SimpleHelpPane(text,
                       this,
                       (bounds.left + bounds.right) / 2,
                       helpId,
                       10000);
}
```

### [UID:00018M] `by-memory/0x004ef510-0x004ef62e.BackPaneHelpPacketDisplayV3.md`

```cpp
void BackPane::ShowHelpFromPacketV3(const unsigned char *packet)
{
    const int helpId = packet[2];
    const unsigned short textLength = ReadPacketWord(packet + 3);

    if (textLength == 0 || textLength > 1023)
        return;

    wchar_t text[1024];
    const int converted = MultiByteToWideChar(0, 0,
                                              reinterpret_cast<const char *>(packet + 5),
                                              textLength,
                                              text,
                                              1023);
    text[converted] = L'\0';

    RectBounds bounds;
    GetBounds(&bounds);

    if (g_pSimpleHelpPane != NULL)
        g_pSimpleHelpPane->Close(true);

    new SimpleHelpPane(text,
                       this,
                       (bounds.left + bounds.right) / 2,
                       helpId,
                       10000);
}
```

### [UID:00044W] `by-memory/0x00610fd0-0x00610fe8.SharedNpal5PaletteResourceString.md`

```cpp
// Shared UTF-16 literal L"NPAL5.PAL" is emitted at source-use sites.
// BackPane::OnPaint uses it in the legacy/non-EPF palette branch, but
// xrefs also prove non-BackPane consumers. Do not create a standalone
// BackPane-owned string definition or duplicate raw .rdata storage here.
```

### [UID:000488] `by-memory/0x00612f38-0x00612f3c.BackGroundPaneRttiLocatorPointer.md`

```cpp
// Compiler-generated RTTI complete-object-locator pointer for
// BackGroundPane immediately before the BackGroundPane vtable island.
// Generated from the BackGroundPane class definition; no standalone
// source declaration or handwritten dword belongs here.
```

### [UID:00028J] `by-memory/0x0067a740-0x0067a744.g_pBackPane.md`

```cpp
BackPane *g_pBackPane = NULL;
```

### [UID:0002VV] `by-memory/0x0067ab7c-0x0067ab80.g_pBackGroundPane.md`

```cpp
BackGroundPane *g_pBackGroundPane = NULL;
```

## Recommended Target Doc Changes

- `by-file/BackPane.md`: raise to `COMPLETION:89`, `CONFIDENCE:91`. Preserve `CANONICAL_OWNER:FILE`, path `NexusTK/map/`, and BackPane/BackGroundPane file ownership. Update Proposed Contents and Changes/Evidence to say the empty-emitter family has report-backed first-draft/no-code dispositions for all 11 current empty markers. Add current MCP session `supervisor_resume_20260629` evidence, generated state `13 total / 2 filled / 11 empty`, and expected generated refresh: no old empty markers remain after implementation except intentional no-code comments for shared literal and RTTI pointer.
- Preserve [UID:00030M] and [UID:000161] as already populated emitters; do not duplicate their bodies in the file page.
- Preserve resource-boundary facts from `by-resource/backpane-background-resources.md`: BackPane source owns filename/palette branch use, not image/palette payload bytes.

## Recommended Support Doc Changes

- `by-class/BackGroundPane.md`: raise to `88/91`; populate formal class declaration; update evidence for constructor/destructor/callback/paint/accessors, tile context `+0x138`, flags `+0x160/+0x161`, `g_pBackGroundPane` zero-initialized storage, vtables, and compiler-only deleting destructor/thunks.
- `by-memory/0x00467510-0x0046782f.BackGroundPaneCoreMethods.md`: raise to `88/91`; insert formal code above; replace stale 95/95 blank-gate wording; record exact MCP decompile facts and no-code proof for thunks/deleting wrapper.
- `by-class/BackPane.md`: raise to `88/91`; populate formal class declaration; update method table for [UID:00030N] and help helpers as first-draft ready; preserve [UID:00030M] and [UID:000161] already-present formal C++.
- `by-memory/0x004679c0-0x00467b2d.BackPaneActivatePaintAndDestructor.md`: raise to `88/91`; insert formal code above; record `FRAME.PAL` / `NPAL5.PAL` branch, `g_useEpfAssets`, `g_pScreenPane` cursor reset, `ClearBackPane`, and deleting-destructor no-code proof.
- `by-memory/0x004eaf20-0x004eb044.BackPaneHelpPacketDisplayV1.md`: raise to `88/91`; insert formal code; preserve zero-xref packet-dispatch caveat.
- `by-memory/0x004ede80-0x004edfa4.BackPaneHelpPacketDisplayV2.md`: raise to `88/91`; insert formal code; preserve zero-xref packet-dispatch caveat.
- `by-memory/0x004ef510-0x004ef62e.BackPaneHelpPacketDisplayV3.md`: raise to `88/91`; insert formal code; change `Nested:-4` to `Nested:0`; preserve zero-xref packet-dispatch caveat.
- `by-memory/0x00610fd0-0x00610fe8.SharedNpal5PaletteResourceString.md`: leave owner/emitter/shared route intact; optionally raise to `89/93`; add no-standalone/no-duplicate formal comment and BackPane paint xref at `0x467a20` with shared non-BackPane xrefs.
- `by-memory/0x00612f38-0x00612f3c.BackGroundPaneRttiLocatorPointer.md`: optionally raise to `88/93`; add compiler-generated no-code formal comment; keep source ownership routed through BackGroundPane/BackPane but do not create source storage.
- `by-memory/0x0067a740-0x0067a744.g_pBackPane.md`: raise to `88/92`; insert `BackPane *g_pBackPane = NULL;`; update old declaration-withheld wording under current source-quality rules.
- `by-memory/0x0067ab7c-0x0067ab80.g_pBackGroundPane.md`: raise to `89/92`; insert `BackGroundPane *g_pBackGroundPane = NULL;`; correct stale static bytes from `ff ff ff ff` to current MCP `00 00 00 00`.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C1 | BackPane file root remains the correct owner/emitter for the BackPane/BackGroundPane source family. | High | Target docs, generated path, MCP body/vtable/global evidence. | `by-file/BackPane.md` Target State / Proposed Contents / Changes | incorporated | applied: `by-file/BackPane.md` now `89/91`, records accepted empty-emitter family disposition and 2026-07-01 B009 evidence. |
| C2 | [UID:00030L] has first-draft source bodies for BackGroundPane constructor/destructor/callback/paint/accessors. | Medium-high | MCP decompile calls `210`-`221`; class docs. | `by-memory/0x00467510-0x0046782f.BackGroundPaneCoreMethods.md` formal C++/evidence | incorporated | applied: formal C++ block populated and validator `000000003761` passed. |
| C3 | BackGroundPane deleting destructor/thunks are compiler output and need no separate handwritten source. | High | MCP decompile `221`; vtable/thunk ranges in docs. | UID00030L no-code proof; `by-class/BackGroundPane.md` method notes | incorporated | applied: UID00030L compiler-wrapper comment and BackGroundPane class evidence preserve no-handwritten wrapper proof. |
| C4 | [UID:00030N] has first-draft source for `OnActivate`, `OnPaint`, and `ClearBackPane`; deleting destructor/thunks are compiler output. | High | MCP decompile `222`-`225`; resource xrefs `323`/`324`; [UID:00030M] ordinary destructor. | UID00030N formal C++/evidence; `by-class/BackPane.md` method notes | incorporated | applied: UID00030N formal C++ block populated and BackPane method table updated. |
| C5 | `BackPane::OnPaint` uses `FRAME.PAL` when `g_useEpfAssets == 1`, otherwise `NPAL5.PAL`. | High | MCP decompile `223`, bytes `310`, xrefs `323`/`324`, resource page. | UID00030N, `by-file/BackPane.md`, shared literal page | incorporated | applied: UID00030N C++ uses the branch and UID00044W records shared `NPAL5.PAL` source-use/no-duplicate disposition. |
| C6 | Help helpers [UID:00018K/L/M] are first-draft C++ eligible despite zero xrefs; keep dispatch caveat. | Medium-high | MCP decompile `226`-`228`; xrefs `330` zero; existing docs. | Three help by-memory docs and `by-class/BackPane.md` | incorporated | applied: all three helper formal C++ blocks populated, all retain zero-xref dispatch caveat, and BackPane class lists the methods. |
| C7 | `g_pBackPane` is source-shaped zero-initialized global storage and should emit `BackPane *g_pBackPane = NULL;`. | High | MCP bytes/int `310`/`311`, xrefs `320`, existing lifecycle docs. | `by-memory/0x0067a740-0x0067a744.g_pBackPane.md` | incorporated | applied: formal C++ block emits `BackPane *g_pBackPane = NULL;`, page now `88/92`. |
| C8 | `g_pBackGroundPane` is source-shaped zero-initialized global storage and should emit `BackGroundPane *g_pBackGroundPane = NULL;`. | High | MCP bytes/int `310`/`311`, xrefs `321`, existing lifecycle docs. | `by-memory/0x0067ab7c-0x0067ab80.g_pBackGroundPane.md` | incorporated | applied: formal C++ block emits `BackGroundPane *g_pBackGroundPane = NULL;`, page now `89/92`. |
| C9 | The old `g_pBackGroundPane` `ff ff ff ff` static-byte claim is stale and must be corrected. | High | MCP bytes/int `310`/`311`. | `by-memory/0x0067ab7c-0x0067ab80.g_pBackGroundPane.md` Layout/Evidence/Changes | incorporated | applied: layout now records `00 00 00 00` and evidence explicitly supersedes the stale claim. |
| C10 | `NPAL5.PAL` is a shared literal; no standalone BackPane-owned string storage should be emitted. | High | MCP bytes `310`, xrefs `323`, resource doc. | `by-memory/0x00610fd0-0x00610fe8.SharedNpal5PaletteResourceString.md` formal no-code proof | incorporated | applied: formal no-duplicate comment added, page now `89/93`. |
| C11 | `0x00612f38` is compiler-generated BackGroundPane RTTI/COL pointer data, not source storage. | High | MCP lookup `102`, bytes/int `310`/`311`, xrefs `322` zero, existing RTTI doc. | `by-memory/0x00612f38-0x00612f3c.BackGroundPaneRttiLocatorPointer.md` formal no-code proof | incorporated | applied: formal compiler-generated RTTI no-code comment added, page now `88/93`. |
| C12 | [UID:00018M] stale `Nested:-4` should be corrected to `Nested:0`. | High | Target metadata inspection; target is an exact function page, not a nested negative-offset child. | `by-memory/0x004ef510-0x004ef62e.BackPaneHelpPacketDisplayV3.md` metadata | incorporated | applied: UID00018M metadata now `Nested:0`. |

## Score And Metadata Recommendation

- [UID:0000HO] `BackPane.md`: `86/88 -> 89/91`, owner/path unchanged.
- [UID:00000R] `BackGroundPane.md`: `86/88 -> 88/91`, owner/emitter unchanged, formal C++ populated.
- [UID:00030L] `BackGroundPaneCoreMethods`: `86/88 -> 88/91`, owner/emitter unchanged, formal C++ populated.
- [UID:00000S] `BackPane.md`: `85/88 -> 88/91`, owner/emitter unchanged, formal C++ populated.
- [UID:00030N] `BackPaneActivatePaintAndDestructor`: `85/88 -> 88/91`, owner/emitter unchanged, formal C++ populated.
- [UID:00018K/L/M]: `86/90 -> 88/91`, owner/emitter unchanged, formal C++ populated; zero-xref dispatch caveat remains.
- [UID:00044W]: optional `88/92 -> 89/93`, shared owner/emitter route unchanged, formal no-duplicate comment.
- [UID:000488]: optional `86/91 -> 88/93`, owner/emitter route unchanged unless supervisor prefers non-emitting compiler metadata; formal no-code comment.
- [UID:00028J]: `85/90 -> 88/92`, source global definition inserted.
- [UID:0002VV]: `88/90 -> 89/92`, source global definition inserted and stale initial-bytes claim corrected.
- Not higher: final source symbol spellings, BackGroundPane event/config/map method names, and help dispatch entries remain inferred or unrecovered.

## Open Questions With Attempted Resolution

- Help packet dispatch entries: checked `xrefs_to` for all three helpers; current result is zero. The bodies are still source-shaped BackPane `thiscall` helpers. This limits final naming/call-chain confidence but no longer supports blank C++.
- BackGroundPane exact field names: checked current decompiles and docs. Offsets and roles are exact, but original spellings are not recovered. Use descriptive names and preserve offset evidence.
- `g_pScreenPane->SetCursor(0,0)` source spelling in `OnActivate`: MCP only proves `sub_5573F0(dword_67A7CC,0,0)` behind the legacy branch. Docs resolve `dword_67A7CC` as screen/cursor context; use source-facing screen/cursor name and retain raw alias as evidence.
- Resource payload ownership: checked `backpane-background-resources.md`. Source emits filename/literal uses; DAT payloads stay resource-packaging, not C++ arrays.

## Validator Results

- Commands run from `E:\NTK\GhidraBridge\source-3\project-documentation` with `--apply --queue-timeout 240 --wait-generated`: scoped file validators for all 12 edited target/support docs.
- Results: all exited `0`, each reported `ok: 1`, and each reported `generated_refresh: completed`.
- Command IDs observed: `000000003759` through `000000003770` for the 12 scoped validators. Exact retained examples: `000000003759` `2026-07-01T07:26:02-04:00` for `by-file/BackPane.md`; `000000003760` `2026-07-01T07:26:14-04:00` for `by-class/BackGroundPane.md`; `000000003761` `2026-07-01T07:26:25-04:00` for UID00030L; `000000003768` `2026-07-01T07:27:40-04:00` for UID000488; `000000003769` `2026-07-01T07:27:51-04:00` for UID00028J; `000000003770` `2026-07-01T07:28:01-04:00` for UID0002VV. The intermediate scoped validators completed sequentially for `by-class/BackPane.md`, UID00030N, UID00018K, UID00018L, UID00018M, and UID00044W.
- Generated output verification: `auto-generated/NexusTK/map/BackPane.cpp` header reports `validator-command-id: 000000003782` and `validator-refreshed-at: 2026-07-01T07:30:18-04:00`. Search verified UID00030L, UID00030N, UID00018K, UID00018L, UID00018M, UID00044W, UID000488, UID00028J, and UID0002VV emit accepted code/comments/declarations and no old `No reconstruction`/`empty marker` text remains.

## Changed Files

- Created: `tools/leaser/Agents/Agent-B009/research/0000HO-BackPane-empty-emitter-family-source-quality.md`
- Modified by Agent-B009 implementation: the 12 target/support by-* docs listed in Implementation Callback Status plus this report ledger/checklist.
- Validator-owned generated refresh occurred for `auto-generated/NexusTK/map/BackPane.cpp` and related validator-generated reports/state through the required scoped validators. No generated file, coverage report, queue, archive, supervisor ledger, by-project-structure doc, or IDA DB was manually edited.

## Implementation Tracking Checklist

Initial report-only pass:
- [x] Supervisor validation required before implementation. Accepted by supervisor callback.
- [x] Target/support docs to update: `by-file/BackPane.md`; `by-class/BackGroundPane.md`; `by-memory/0x00467510-0x0046782f.BackGroundPaneCoreMethods.md`; `by-class/BackPane.md`; `by-memory/0x004679c0-0x00467b2d.BackPaneActivatePaintAndDestructor.md`; `by-memory/0x004eaf20-0x004eb044.BackPaneHelpPacketDisplayV1.md`; `by-memory/0x004ede80-0x004edfa4.BackPaneHelpPacketDisplayV2.md`; `by-memory/0x004ef510-0x004ef62e.BackPaneHelpPacketDisplayV3.md`; `by-memory/0x00610fd0-0x00610fe8.SharedNpal5PaletteResourceString.md`; `by-memory/0x00612f38-0x00612f3c.BackGroundPaneRttiLocatorPointer.md`; `by-memory/0x0067a740-0x0067a744.g_pBackPane.md`; `by-memory/0x0067ab7c-0x0067ab80.g_pBackGroundPane.md`.
- [x] Current target state and actual evidence checked recorded.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim.
- [x] Metadata/score changes applied as listed in Score And Metadata Recommendation.
- [x] Score-limiting blockers researched to resolution or implementation-ready recommendations: stale blank-C++ gate rejected; singleton globals converted to source definitions; shared literal and RTTI pointer given formal no-code/no-duplicate proofs; help zero-xref caveat retained but not allowed to block first-draft C++.
- [x] Owner/emitter/reconstructable changes applied or preserved: BackPane/BackGroundPane owner routes preserved; no new owner split required.
- [x] Split/rename/new-child changes applied: no new child required; [UID:00018M] `Nested:-4 -> 0`.
- [x] Source-placement, range/split/padding/reclassification, or IDA rename/type/comment changes applied or confirmed not applicable: no IDA DB changes; docs record source-facing names and rejected raw aliases.
- [x] First-draft C++ or no-code proof applied: exact formal insertion text supplied for all 11 current empty markers.
- [x] Third-party import directive confirmed not applicable.
- [x] Exact target/support doc facts incorporated at report-level detail.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved: stale 95/95 blank gates, stale `g_pBackGroundPane` bytes, zero-xref help dispatch caveat, shared `NPAL5.PAL` no-duplicate proof, compiler RTTI no-code proof.
- [x] Wave2/Wave3 mentions or artifacts encountered and ignored/rejected as stale alias evidence.
- [x] Open questions documented as evidence-backed unresolved: help dispatch entries and final original field names remain confidence caps only.
- [x] Validators run after implementation: scoped validators for every edited doc with `--apply --wait-generated`.
- [x] Generated report refresh completed: `auto-generated/NexusTK/map/BackPane.cpp` refreshed with first-draft code/comments/declarations and no old empty markers; no manual coverage-report edit performed.

Implementation callback pass:
- [x] Report accepted by supervisor for implementation.
- [x] All accepted target/support doc details incorporated at report-level detail.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim.
- [x] Metadata/score/owner/emitter/split/rename/C++ changes applied or explicitly not applied with reason.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved.
- [x] Open questions resolved or documented with evidence-backed unresolved rationale.
- [x] Validators run and results recorded.
- [x] Generated report refresh completed by validator.
- [x] Remaining unapplied accepted items listed with exact blocker: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B009","command_id":"000000004165","destination_path":"executed-b-agent-research/B009/0000HO-BackPane-empty-emitter-family-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B009/research/0000HO-BackPane-empty-emitter-family-source-quality.md","timestamp":"2026-07-01T15:00:00","uid":"0000HO"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
