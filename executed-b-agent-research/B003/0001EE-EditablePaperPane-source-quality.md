** TARGET-REPORT-UID:0001EE **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B003-goal2-editable-paper-pane-source-quality-0001EE-20260618

Target: [UID:0001EE] `by-memory/0x00545170-0x00545e3b.EditablePaperPane.md`

Final recommendation: keep `0x00545170-0x00545e3b` as a source-bearing `EditablePaperPane` class-method aggregate owned by [UID:000048][EditablePaperPane] and emitted through [UID:0000IX][EditablePaperPane.cpp]. Raise the target from `84/86` to `87/88` after applying the source-quality notes below. The open issues are no longer severe enough to keep formal C++ blank: the unresolved byte at `+0x26d` can be documented as a parsed-but-cleared protocol/reserved status byte, and the two paper-open wrappers at `0x005128a0` and `0x00512900` are no-route MapPane-side factory wrappers, not evidence against `EditablePaperPane` ownership.

Do not move this range to a non-emitting split/index. Optional later method-level children would improve generated-source granularity, but they are not required before populating a first-draft source block for the aggregate.

## Evidence Checked

- Workflow and scoring instructions:
  - `tools/leaser/Agents/Supervisor.md`
  - `tools/leaser/Agents/Agent-B003/goal.md`
  - `by-structure.md`
  - `by-project-structure/proposed-source-tree.md`
  - `by-project-structure/inference_research.md`
  - `tools/validator_README.txt`
- Primary target:
  - [UID:0001EE] `by-memory/0x00545170-0x00545e3b.EditablePaperPane.md`
- Direct support pages:
  - [UID:0000IX] `by-file/EditablePaperPane.md`
  - [UID:000048] `by-class/EditablePaperPane.md`
  - [UID:0001XF] `by-type/by-vtable/EditablePaperPaneVtables.md`
  - [UID:0002NC] `by-memory/0x00621afc-0x00621b98.EditablePaperPaneVtableData.md`
  - [UID:0001EF] `by-memory/0x00545ddd-0x00545df3.EditablePaperPaneAdjustorThunks.md`
- Neighboring and caller/support pages:
  - [UID:0000L3] `by-file/MapPane.md`
  - [UID:00007Q] `by-class/MapPane.md`
  - [UID:0001AT] `by-memory/0x00506970-0x0050e320.MapPaneInputPacketRenderCore.md`
  - [UID:0001AW] `by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md`
  - `by-memory/0x006219e8-0x00621db8.PaneParcelReadOnlyData.md`
  - `by-memory/-ignored.md`
  - `by-memory/-coverage-report.md`
- Prior wrapper/split research checked:
  - `tools/leaser/Agents/Agent-B001/research/executed/older/0001AW-mappane-packet-source-split-audit.md`
  - `tools/leaser/Agents/Agent-B001/research/executed/older/0001AW-mappane-packet-source-split-audit-continuation-batch6.md`
  - `tools/leaser/Agents/Agent-B001/research/executed/older/0001AW-mappane-packet-source-split-audit-continuation-batch8.md`
- Generated C lead checked only as a secondary lead, not as authority:
  - `simroot_v2/class_EditablePaperPane.cpp`
  - `simroot_v2/class_MapPane.cpp`
- Local binary scan source:
  - `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
  - Image base confirmed as `0x00400000`.
  - `.text` VA range confirmed as `0x00401000-0x0060c440` approximately, `.rdata` starts at `0x0060d000`.
- Fresh live IDA MCP was attempted at `http://127.0.0.1:13337/mcp` and failed with connection refused/unavailable. This pass therefore uses existing live-IDA-backed docs plus local PE byte/xref scans. The lack of fresh IDA is the reason this recommendation stops at `87/88` instead of a final-audit score.

Local PE scan results that should be preserved in the target/support docs:

| Address or target | Evidence |
| --- | --- |
| `0x00545170` | rel32 calls at `0x00508338`, `0x0050836b`, `0x005128e5`, and `0x00512945`; no dword pointer hits. The first two are direct MapPane packet-dispatch construction sites, the latter two are no-route wrappers. |
| `0x00545220` | vtable dword hit at `0x00621b44`; no direct rel32 calls. This is the action-handler virtual slot. |
| `0x00545250` | vtable dword hit at `0x00621b58`; no direct rel32 calls. This is the common content/control initializer virtual/helper slot. |
| `0x00545660` | rel32 call from constructor body at `0x005451fe`; editable-packet parser. |
| `0x00545770` | rel32 call from constructor body at `0x005451e0`; read-only-packet parser. |
| `0x00545880` | rel32 call from action handler at `0x00545235`; save serializer. |
| `0x005459b0` | vtable dword hit at `0x00621b50`; border renderer. |
| `0x00545d50` | vtable dword hit at `0x00621b4c`; background renderer. |
| `0x00545ddd` | vtable dword hit at `0x00621b60`; secondary destructor adjustor thunk. |
| `0x00545de8` | vtable dword hit at `0x00621b90`; tertiary destructor adjustor thunk. |
| `0x00545e00` | vtable dword hit at `0x00621afc`; scalar deleting destructor entry. |
| `0x005128a0` | no dword pointer hits and no rel32 call hits in the PE scan; raw bytes show allocation of `0x280`, call to `0x00545170` with mode `0`, boolean success return, and `ret 4`. |
| `0x00512900` | no dword pointer hits and no rel32 call hits in the PE scan; raw bytes show allocation of `0x280`, call to `0x00545170` with mode `1`, boolean success return, and `ret 4`. |
| `0x00621afc` | dword hit from constructor store site `0x005451b9`; primary vtable base. |
| `0x00621b60` | dword hit from constructor store site `0x005451c3`; secondary vtable base. |
| `0x00621b90` | dword hit from constructor store site `0x005451cd`; tertiary vtable base. |
| `0x00621b98` | UTF-16 `LINE001.EPD`; dword/string hits at `0x00545a2e`, `0x00545a40`, `0x00545a55`, `0x00545a6a`, `0x00545a7f`, `0x00545a94`, `0x00545aa9`, `0x00545abe`, and `0x00545d7b`. |

## Heuristic / Inference Reanalysis And Validation

### Aggregate, Split, Owner, And Emitter

Best current source-shape decision:

- Keep [UID:0001EE] as a reconstructable, source-bearing aggregate for the `EditablePaperPane` class methods.
- Keep `CANONICAL_OWNER:000048`.
- Keep `EMITTER_UIDS:000048`.
- Keep the class/file route through [UID:0000IX] `NexusTK/ui/dialogs/EditablePaperPane.cpp`.
- Do not convert the page to `RECONSTRUCTABLE:FALSE`, a non-emitting split/index, or a MapPane-owned page.

Evidence:

- The range is contiguous class behavior: constructor/mode dispatch, action handler, common UI setup, editable parser, read-only parser, save serializer, border renderer, background renderer, and compiler-generated destructor support.
- Direct MapPane construction sites at `0x00508338` and `0x0050836b` open this dialog for packet opcodes `0x1b` and `0x35`, but the parsing, UI setup, rendering, and serialization logic are inside the `EditablePaperPane` class range.
- The vtable data page and vtable-family page tie `0x00545220`, `0x00545250`, `0x005459b0`, `0x00545d50`, and `0x00545e00` to `EditablePaperPane` virtual slots.
- The constructor stores the three `EditablePaperPane` vtable bases at object offsets `+0x0`, `+0xa0`, and `+0xa4`.
- `LINE001.EPD` refs come only from the drawing methods in this class family, not from a generic text pane or MapPane renderer.

Rejected alternatives:

- Non-emitting split/index: rejected because the page owns several source-authored methods and already has a valid class/file emitter route.
- Move ownership to `MapPane`: rejected because MapPane only dispatches packets and constructs the pane. It does not own the class fields, text edit child setup, paper renderer, or save serializer.
- Split every method before entering C++: optional but not required. The aggregate passes the active code-entry gate after this source-quality update; method children can be created later if the supervisor wants finer generated-source fragments.
- Treat `0x005128a0`/`0x00512900` as required children of this range: rejected because they are outside the target, have no current caller/pointer route, and are factory wrappers that allocate/open the pane rather than implement the pane.

Impact:

- Source placement stays under `EditablePaperPane`.
- Formal C++ can be populated with a first draft for the source-authored methods in this range.
- The excluded compiler artifacts should be documented, not hand-authored as ordinary method bodies.

### Method Names And Signatures

Recommended source-facing names and signatures:

| Range | Current role | Recommended source name/signature | Evidence and notes |
| --- | --- | --- | --- |
| `0x00545170-0x00545217` | Constructor/mode dispatch | `EditablePaperPane::EditablePaperPane(const unsigned char *packet, PaperOpenMode mode)` | Binary is thiscall with `(this, packet, mode)`. Mode `0` routes to editable parser; mode `1` routes to read-only parser. Direct MapPane construction pushes mode `0` for opcode `0x1b` and mode `1` for opcode `0x35`; wrappers do the same. |
| `0x00545220-0x0054524b` | Action handler | `void EditablePaperPane::OnDialogAction(int actionId)` | Primary vtable slot `+0x48`; action `0` closes the pane and saves first only in editable mode. |
| `0x00545250-0x0054565b` | Common text/control/content setup | `void EditablePaperPane::InitializePaperContent(wchar_t *text)` | Called by both parsers after multibyte-to-wide conversion and protocol line-break normalization. Mutates the supplied wide buffer by converting tabs to carriage returns before insertion, so `wchar_t *` is more accurate than `const wchar_t *`. |
| `0x00545660-0x00545767` | Editable packet parser | `void EditablePaperPane::ParseEditablePacket(const unsigned char *packet)` | Reads paper id, reserved/status byte, width, height, 16-bit text length, and multibyte payload from editable packet layout. |
| `0x00545770-0x00545877` | Read-only packet parser | `void EditablePaperPane::ParseReadOnlyPacket(const unsigned char *packet)` | Reads reserved/status byte, width, height, centered flag, 16-bit text length, and multibyte payload from read-only packet layout. No paper id in this inbound format. |
| `0x00545880-0x005459a7` | Save serializer | `void EditablePaperPane::SavePaperContent()` | Called by `OnDialogAction(0)` only when mode is editable. Emits opcode `0x23`, paper id, 16-bit text byte count, and normalized text payload. |
| `0x005459b0-0x00545d46` | Border renderer | `void EditablePaperPane::DrawBorder()` or `void EditablePaperPane::DrawPaperBorder()` | Primary vtable slot `+0x54`; consumes `LINE001.EPD` frames `0..7`. Existing docs use `DrawBorder`; keep that unless the surrounding source tree uses `DrawPaperBorder` naming. |
| `0x00545d50-0x00545dc1` | Background renderer | `void EditablePaperPane::DrawBackground()` or `void EditablePaperPane::DrawPaperBackground()` | Primary vtable slot `+0x50`; consumes `LINE001.EPD` frame `8`. Existing docs use `DrawBackground`; keep that unless local convention prefers `DrawPaperBackground`. |
| `0x00545ddd-0x00545df3` | Adjustor thunks | no source method | Compiler-generated secondary/tertiary destructor adjustor thunks. Keep child [UID:0001EF] ignored. |
| `0x00545e00-0x00545e3b` | Scalar deleting destructor | no explicit scalar-deleting source body | Compiler emits this from the class destructor/vtable. If the class source needs an explicit destructor, source should be ordinary `EditablePaperPane::~EditablePaperPane() = default;` or an empty destructor, not a scalar-deleting wrapper implementation. |

`PaperOpenMode` should be a documented enum or named constants:

```cpp
enum PaperOpenMode {
    kPaperOpenEditable = 0,
    kPaperOpenReadOnly = 1,
};
```

### Field And Buffer Interpretation

Recommended tail field names and meanings:

| Offset | Recommended name/type | Evidence and source-quality status |
| --- | --- | --- |
| `+0x26c` | `uint8_t m_paperId` | Editable parser reads packet byte `+1`; save serializer writes this value as outbound opcode `0x23` byte `+1`. No read-only parser paper id is present. This field is resolved. |
| `+0x26d` | `uint8_t m_packetStatusByte` or `uint8_t m_reservedPacketStatus` | Both parsers read a byte into this offset and then clear it before common initialization. No current checked evidence shows a later read in this target. High-probability source role is a packet-layout status/flags/reserved byte retained by the original class layout but not used by the current UI. Do not keep this as an unresolved `unknown_26d`; document that exact business semantics remain unproven but target behavior is resolved. |
| `+0x26e` | `uint8_t m_widthTiles` | Used to compute pixel width as `(m_widthTiles + 2) * 16`. |
| `+0x26f` | `uint8_t m_heightTiles` | Used to compute pixel height as `(m_heightTiles + 3) * 16`. |
| `+0x270` | `uint16_t m_textLength` or `int m_textLength` if class layout requires word widening | Stores the `MultiByteToWideChar` result length and is used by centered read-only layout. Existing docs call this `m_textLength`; retain. |
| `+0x278` | `int m_paperMode` or `PaperOpenMode m_paperMode` | Constructor writes mode, action handler checks mode before save, initializer chooses editable/read-only control behavior and button string id. |
| `+0x27c` | `bool m_bCentered` or `bool m_centerText` | Read-only parser writes packet byte `+4`; initializer uses this only for read-only centered text layout. Existing docs call this `m_bCentered`; source-facing name `m_centerText` is clearer but changing is optional. |
| `+0x0`, `+0xa0`, `+0xa4` | vtable views | Constructor stores primary, secondary, and tertiary `EditablePaperPane` vtable bases; no source field names should be invented for these beyond inheritance/vtable documentation. |

Text/control/editor buffer inference:

- The large text conversion buffers are stack-local, not persistent class fields. Parser bodies copy packet multibyte text into an approximately `8000` byte temporary, convert to a wide temporary with `MultiByteToWideChar`, store the converted length in `+0x270`, normalize the pending protocol/status byte by clearing `+0x26d`, and call the common initializer.
- The save serializer uses stack temporaries for wide text, normalized wide text, and an outbound packet buffer. The packet buffer capacity is approximately `32000` bytes; text conversion limits remain approximately `8000`.
- The text editor is stored in the dialog/control tree, not as a confirmed tail field in this page. The initializer adds the close/action button first and the `TextEditControlPane` second; save reacquires the editor through the control list (`GetControlAt(1)` in the generated lead). This supports documenting "editor control index 1" rather than inventing a dedicated `m_editor` field unless a future layout pass proves one.
- The dependency should remain `TextEditControlPane`. Do not replace this with a stale `TextEditPane` owner. Scrollbar hiding is a child text-control behavior reached through the text-edit control; it is not evidence for a separate `DrawScrollbarPartF` source owner in this target.

### Packet And Protocol Details

Inbound editable open packet, MapPane opcode `0x1b`:

| Offset | Meaning |
| --- | --- |
| `+0` | opcode `0x1b` at the dispatcher level; constructor receives a pointer to the packet/payload base used by the parser. |
| `+1` | `m_paperId`. |
| `+2` | `m_packetStatusByte` / reserved status byte; parsed then cleared. |
| `+3` | `m_widthTiles`. |
| `+4` | `m_heightTiles`. |
| `+5..+6` | big-endian 16-bit multibyte text length. |
| `+7..` | multibyte text bytes converted with `MultiByteToWideChar` code page `0` / default ANSI and flags `0`. |

Inbound read-only open packet, MapPane opcode `0x35`:

| Offset | Meaning |
| --- | --- |
| `+0` | opcode `0x35` at the dispatcher level. |
| `+1` | `m_packetStatusByte` / reserved status byte; parsed then cleared. |
| `+2` | `m_widthTiles`. |
| `+3` | `m_heightTiles`. |
| `+4` | `m_bCentered` / `m_centerText`. |
| `+5..+6` | big-endian 16-bit multibyte text length. |
| `+7..` | multibyte text bytes converted with `MultiByteToWideChar` code page `0` / default ANSI and flags `0`. |

Outbound save packet, opcode `0x23`:

| Offset | Meaning |
| --- | --- |
| `+0` | opcode `0x23`. |
| `+1` | `m_paperId`. |
| `+2..+3` | big-endian 16-bit multibyte text byte count only. This is not the total packet size. |
| `+4..` | `WideCharToMultiByte` output after line-break normalization. |

Save packet length semantics:

- The length field is the text payload byte count.
- The send length is `textByteCount + 4`.
- The trailing zero written after the payload is a local terminator/safety byte and should not be counted as part of the protocol payload unless a later send-helper audit proves otherwise.

Line-break normalization:

- Inbound display path converts tab (`0x09`) characters to carriage return (`0x0d`) after multibyte-to-wide conversion and before inserting into the text control.
- Save path converts carriage returns back to tabs before `WideCharToMultiByte`.
- This is protocol-facing normalization, not Windows CRLF normalization. Do not document it as CRLF expansion.

MapPane relationship:

- MapPane is the dispatcher/owner for packet cases `0x1b` and `0x35`.
- `EditablePaperPane` owns packet payload parsing, dialog construction, text edit setup, rendering, and outbound save serialization.
- Caller relationship therefore validates the current `EditablePaperPane` owner/emitter and does not support moving this target into `MapPane.cpp`.

### Resource And Frame Semantics

`LINE001.EPD` is a source literal/resource name for the paper frame. Existing docs already reject the stale `0x0045004e` LodePNG-looking value at `0x00621b9c` as string-byte pollution. Keep that rejection.

Frame mapping recommended for docs:

| Frame | Role |
| --- | --- |
| `0` | top-left corner |
| `1` | top edge tile |
| `2` | top-right corner |
| `3` | right edge tile |
| `4` | bottom-right corner |
| `5` | bottom edge tile |
| `6` | bottom-left corner |
| `7` | left edge tile |
| `8` | interior/background fill tile |

Support-doc status:

- `by-file/EditablePaperPane.md`, `by-class/EditablePaperPane.md`, `by-type/by-vtable/EditablePaperPaneVtables.md`, and `by-memory/0x00621afc-0x00621b98.EditablePaperPaneVtableData.md` already document `LINE001.EPD` at useful detail.
- No dedicated `by-resource` page for `LINE001.EPD` was found by `rg -n "LINE001\.EPD"` under `by-resource`. Creating one is optional and outside this report-only target. If the supervisor creates one later, use the frame map above and tie xrefs to `0x005459b0` and `0x00545d50`.

### Wrapper Reanalysis

`0x005128a0` and `0x00512900` should be documented as no-route, retained MapPane/paper factory wrappers:

| Range | Recommended name if later documented | Evidence | Disposition |
| --- | --- | --- | --- |
| `0x005128a0-0x005128fd` | `MapPaneCreateEditablePaperPaneWrapper` or `OpenEditablePaperPaneFromPacket` | Allocates `0x280`, calls `EditablePaperPane` constructor with mode `0`, returns success, `ret 4`; local PE scan found no dword or rel32 callers. | Outside [UID:0001EE]. Do not block `EditablePaperPane` C++; keep as no-route roadmap under MapPane packet helper research unless a pointer-table route is found. |
| `0x00512900-0x0051295d` | `MapPaneCreateReadOnlyPaperPaneWrapper` or `OpenReadOnlyPaperPaneFromPacket` | Allocates `0x280`, calls `EditablePaperPane` constructor with mode `1`, returns success, `ret 4`; local PE scan found no dword or rel32 callers. | Same disposition. |

Rejected wrapper alternatives:

- Treating these wrappers as current dispatcher targets: rejected because MapPane direct construction sites at `0x00508338` and `0x0050836b` already call the constructor, and the wrappers have no confirmed caller or pointer-table route.
- Treating these wrappers as `EditablePaperPane` source methods: rejected because they allocate/open the pane from an external packet context and sit inside the MapPane packet helper neighborhood.
- Creating no-caller child pages immediately: prior B001 continuation batch 8 explicitly recommends against creating children at `0x00512840`, `0x005128a0`, or `0x00512900` until a pointer/dispatcher route is found. This pass validates that conclusion.

### Vtable, Adjustor Thunk, And Destructor Policy

- [UID:0002NC] remains the exact vtable-data child for the three `EditablePaperPane` vtable views. Its final C++ should remain blank because vtable bytes are compiler-emitted from class declarations.
- [UID:0001EF] remains ignored. The two thunks subtract `this` by `0xa0` or `0xa4` and jump to `0x00545e00`. They are compiler-generated destructor adjustors, not handwritten paper-pane behavior.
- The scalar deleting destructor at `0x00545e00-0x00545e3b` is compiler-generated destructor support. The source representation is an ordinary/default destructor, not a hand-authored scalar-deleting function. This does not block first-draft C++ for the source-authored methods in the aggregate.
- Replace stale "95/95 code gate" wording in supporting pages with the active gate from `by-structure.md`: source C++ may be entered when `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS` is nonblank and routes to generated source, and `(COMPLETION + CONFIDENCE) / 2 > 85`, provided names/dependencies/source placement are strong enough.

## Recommended Metadata And Score Changes

Primary target [UID:0001EE]:

```text
COMPLETION:87
CONFIDENCE:88
RECONSTRUCTABLE:TRUE
CANONICAL_OWNER:000048
EMITTER_UIDS:000048
```

Reasoning:

- Completion should rise from `84` to `87` because the main open blockers are now reclassified:
  - `+0x26d` is not fully business-named, but behavior and source role are documented well enough as a protocol/reserved packet status byte parsed then cleared.
  - `0x005128a0` and `0x00512900` are no-route MapPane-side wrapper bodies, not target ownership blockers.
  - `LINE001.EPD` frame semantics are sufficiently resolved for this target.
  - Packet layouts and save length semantics are resolved at source-quality draft level.
- Confidence should rise from `86` to `88` because existing live-IDA-backed pages agree with local PE ref scans, vtable evidence, direct MapPane construction, and wrapper no-route status.
- Do not raise above `88` without a fresh live IDA pass or a final helper/type naming audit.

Support pages:

- [UID:0000IX] `by-file/EditablePaperPane.md`: recommend `COMPLETION:87`, `CONFIDENCE:88` if the file page incorporates the field/wrapper/protocol notes below. If the supervisor only patches [UID:0001EE], leave the file page at its current score and add a cross-reference to this report.
- [UID:000048] `by-class/EditablePaperPane.md`: recommend `COMPLETION:87`, `CONFIDENCE:88` after adding the field/protocol table and wrapper disposition.
- [UID:0001XF] `EditablePaperPaneVtables.md`: no score change required. Only replace stale gate wording if present.
- [UID:0002NC] `EditablePaperPaneVtableData.md`: no score change required. Keep final C++ blank.
- [UID:0001EF] `EditablePaperPaneAdjustorThunks.md`: no score change required in the page if it already says `85/90`; only update stale coverage row from `80%` to `85%`.

## First-Draft C++ Recommendation

The supervisor should populate formal C++ for [UID:0001EE] after applying the metadata and source-quality text updates above. The draft below is appropriate for a first source-bearing aggregate block, not a final-audit buildable translation unit. Helper names are descriptive and should be reconciled with packet/UI helper docs during later source-tree integration.

Do not emit source bodies for:

- `0x00545ddd-0x00545df3` adjustor thunks.
- vtable bytes in [UID:0002NC].
- a raw scalar-deleting destructor wrapper. If a source destructor is needed, use an ordinary/default destructor declaration or definition.

Recommended first-draft C++:

```cpp
namespace {
enum PaperOpenMode {
    kPaperOpenEditable = 0,
    kPaperOpenReadOnly = 1,
};

constexpr int kPaperTilePixels = 16;
constexpr int kPaperTextLinePixels = 12;
constexpr int kPaperTextBufferBytes = 8000;
constexpr int kPaperPacketBufferBytes = 32000;
constexpr unsigned char kPaperSaveOpcode = 0x23;
constexpr wchar_t kPaperFrameResource[] = L"LINE001.EPD";

unsigned short ReadBigEndianWord(const unsigned char *p)
{
    return static_cast<unsigned short>((p[0] << 8) | p[1]);
}

void WriteBigEndianWord(unsigned char *p, unsigned short value)
{
    p[0] = static_cast<unsigned char>(value >> 8);
    p[1] = static_cast<unsigned char>(value);
}

void NormalizeTabsToReturns(wchar_t *text)
{
    for (wchar_t *p = text; *p != 0; ++p) {
        if (*p == L'\t') {
            *p = L'\r';
        }
    }
}

void NormalizeReturnsToTabs(wchar_t *text)
{
    for (wchar_t *p = text; *p != 0; ++p) {
        if (*p == L'\r') {
            *p = L'\t';
        }
    }
}
}

EditablePaperPane::EditablePaperPane(const unsigned char *packet, PaperOpenMode mode)
    : DialogPane(L"", 7, true),
      m_paperId(0),
      m_packetStatusByte(0),
      m_widthTiles(0),
      m_heightTiles(0),
      m_textLength(0),
      m_paperMode(mode),
      m_centerText(false)
{
    if (mode == kPaperOpenReadOnly) {
        ParseReadOnlyPacket(packet);
    } else {
        ParseEditablePacket(packet);
    }
}

void EditablePaperPane::OnDialogAction(int actionId)
{
    if (actionId != 0) {
        return;
    }

    if (m_paperMode == kPaperOpenEditable) {
        SavePaperContent();
    }

    DismissDialogPane(this);
}

void EditablePaperPane::ParseEditablePacket(const unsigned char *packet)
{
    char textBytes[kPaperTextBufferBytes];
    wchar_t wideText[kPaperTextBufferBytes];

    m_paperId = packet[1];
    m_packetStatusByte = packet[2];
    m_widthTiles = packet[3];
    m_heightTiles = packet[4];

    const unsigned short byteCount = ReadBigEndianWord(packet + 5);
    const int copyCount = min<int>(byteCount, kPaperTextBufferBytes - 1);
    memcpy(textBytes, packet + 7, copyCount);
    textBytes[copyCount] = 0;

    const int wideCount = MultiByteToWideChar(
        0, 0, textBytes, copyCount, wideText, kPaperTextBufferBytes - 1);
    wideText[wideCount] = 0;
    m_textLength = static_cast<unsigned short>(wideCount);

    m_packetStatusByte = 0;
    InitializePaperContent(wideText);
}

void EditablePaperPane::ParseReadOnlyPacket(const unsigned char *packet)
{
    char textBytes[kPaperTextBufferBytes];
    wchar_t wideText[kPaperTextBufferBytes];

    m_packetStatusByte = packet[1];
    m_widthTiles = packet[2];
    m_heightTiles = packet[3];
    m_centerText = packet[4] != 0;

    const unsigned short byteCount = ReadBigEndianWord(packet + 5);
    const int copyCount = min<int>(byteCount, kPaperTextBufferBytes - 1);
    memcpy(textBytes, packet + 7, copyCount);
    textBytes[copyCount] = 0;

    const int wideCount = MultiByteToWideChar(
        0, 0, textBytes, copyCount, wideText, kPaperTextBufferBytes - 1);
    wideText[wideCount] = 0;
    m_textLength = static_cast<unsigned short>(wideCount);

    m_packetStatusByte = 0;
    InitializePaperContent(wideText);
}

void EditablePaperPane::InitializePaperContent(wchar_t *text)
{
    NormalizeTabsToReturns(text);

    const int paneWidth = (m_widthTiles + 2) * kPaperTilePixels;
    const int paneHeight = (m_heightTiles + 3) * kPaperTilePixels;

    Rect closeRect(-200, -200, -140, -180);
    const int closeStringId = (m_paperMode == kPaperOpenEditable) ? 95 : 96;
    AddControl(CreatePaperCloseButton(0, closeStringId, closeRect));

    Rect textRect;
    if (m_paperMode == kPaperOpenReadOnly && m_centerText) {
        const int textPixelWidth = (m_textLength * kPaperTilePixels) / 2;
        const int left = (paneWidth - textPixelWidth) / 2;
        const int top = (paneHeight - kPaperTextLinePixels) / 2;
        textRect.Set(left, top, left + textPixelWidth, top + kPaperTextLinePixels);
    } else {
        textRect.Set(
            kPaperTilePixels,
            kPaperTilePixels,
            paneWidth - kPaperTilePixels,
            (m_heightTiles + 1) * kPaperTilePixels);
    }

    textRect.bottom -= textRect.Height() % kPaperTextLinePixels;

    TextEditControlPane *editor = CreatePaperTextEditor(1, textRect);
    AddControl(editor);
    editor->SetScrollbarsVisible(false);

    if (m_paperMode == kPaperOpenEditable) {
        editor->SetLimits(42, 250);
        editor->SetReadOnly(false);
        editor->SetFocus(true);
    } else {
        editor->SetLimits(2000, 30000);
        editor->SetReadOnly(true);
        editor->SetFocus(false);
    }

    editor->SetText(text);
    editor->SetSelection(0, 0);

    SetCurrentControlId(0);
    if (m_paperMode == kPaperOpenReadOnly) {
        SetActiveControlId(0);
    }

    Rect bounds;
    bounds.Set(320 - paneWidth / 2, 240 - paneHeight / 2,
               320 + paneWidth / 2, 240 + paneHeight / 2);
    SetBounds(bounds);
    SetParentPane(GetRootPane());
    SlideOpen();
}

void EditablePaperPane::SavePaperContent()
{
    wchar_t wideText[kPaperTextBufferBytes];
    unsigned char packet[kPaperPacketBufferBytes];

    TextEditControlPane *editor =
        static_cast<TextEditControlPane *>(GetControlAt(1));
    if (editor == 0) {
        return;
    }

    editor->GetText(wideText, kPaperTextBufferBytes - 1);
    wideText[kPaperTextBufferBytes - 1] = 0;
    NormalizeReturnsToTabs(wideText);

    packet[0] = kPaperSaveOpcode;
    packet[1] = m_paperId;

    const int byteCount = WideCharToMultiByte(
        0, 0, wideText, -1,
        reinterpret_cast<char *>(packet + 4),
        kPaperTextBufferBytes - 1,
        0, 0);
    if (byteCount <= 0) {
        return;
    }

    const int textByteCount = byteCount - 1;
    WriteBigEndianWord(packet + 2, static_cast<unsigned short>(textByteCount));

    const int sendLength = textByteCount + 4;
    if (sendLength >= kPaperPacketBufferBytes) {
        return;
    }

    packet[sendLength] = 0;
    SendClientPacket(packet, sendLength);
}

void EditablePaperPane::DrawBorder()
{
    const Rect bounds = GetBounds();
    const int left = bounds.left;
    const int top = bounds.top;
    const int right = bounds.right;
    const int bottom = bounds.bottom;

    DrawPaperFrame(kPaperFrameResource, 0, left, top);
    DrawPaperFrame(kPaperFrameResource, 2, right - kPaperTilePixels, top);
    DrawPaperFrame(kPaperFrameResource, 6, left, bottom - kPaperTilePixels);
    DrawPaperFrame(kPaperFrameResource, 4, right - kPaperTilePixels, bottom - kPaperTilePixels);

    for (int x = left + kPaperTilePixels; x < right - kPaperTilePixels; x += kPaperTilePixels) {
        DrawPaperFrame(kPaperFrameResource, 1, x, top);
        DrawPaperFrame(kPaperFrameResource, 5, x, bottom - kPaperTilePixels);
    }

    for (int y = top + kPaperTilePixels; y < bottom - kPaperTilePixels; y += kPaperTilePixels) {
        DrawPaperFrame(kPaperFrameResource, 7, left, y);
        DrawPaperFrame(kPaperFrameResource, 3, right - kPaperTilePixels, y);
    }
}

void EditablePaperPane::DrawBackground()
{
    Rect fill = GetBounds();
    fill.Deflate(kPaperTilePixels, kPaperTilePixels);
    DrawTiledPaperFrame(kPaperFrameResource, 8, fill);
}
```

Draft limitations that should remain explicit:

- `CreatePaperCloseButton`, `CreatePaperTextEditor`, `DismissDialogPane`, `GetRootPane`, `SendClientPacket`, `DrawPaperFrame`, and `DrawTiledPaperFrame` are descriptive helper names. Later integration should replace them with the established local helper API names.
- The exact class declaration/inheritance is supplied by the class/vtable docs, not by this by-memory draft.
- Stack buffer sizes and range checks are source-equivalent but should be tightened against final decompiler/disassembly before a final-audit score.
- The source destructor should be represented by the class declaration/ordinary destructor policy, not by a scalar-deleting wrapper body.

## Exact Supervisor Changes Required

Apply these changes manually; this report did not edit shared by-* docs.

1. In [UID:0001EE] `by-memory/0x00545170-0x00545e3b.EditablePaperPane.md`, replace the metadata values with:

```text
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:000048 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:000048 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

2. In [UID:0001EE], add this source-quality note after the current high-level description or status section:

```markdown
### 2026-06-18 Source-Quality Reanalysis

This range remains a source-bearing `EditablePaperPane` class-method aggregate owned by [UID:000048][EditablePaperPane] and emitted through [UID:0000IX][EditablePaperPane.cpp]. It should not be converted to a non-emitting split/index. The range contains source-authored constructor/mode dispatch, action handling, editable/read-only packet parsing, common paper content initialization, save serialization, and paper frame/background rendering. The adjustor thunks and scalar deleting destructor support are compiler artifacts and should be documented/excluded rather than hand-authored as ordinary methods.

Recommended source names are `EditablePaperPane::EditablePaperPane(const unsigned char *packet, PaperOpenMode mode)`, `OnDialogAction(int actionId)`, `InitializePaperContent(wchar_t *text)`, `ParseEditablePacket(const unsigned char *packet)`, `ParseReadOnlyPacket(const unsigned char *packet)`, `SavePaperContent()`, `DrawBorder()`, and `DrawBackground()`. `PaperOpenMode` values are `0` for editable opcode `0x1b` and `1` for read-only opcode `0x35`.

Tail fields should be documented as `+0x26c m_paperId`, `+0x26d m_packetStatusByte` or `m_reservedPacketStatus`, `+0x26e m_widthTiles`, `+0x26f m_heightTiles`, `+0x270 m_textLength`, `+0x278 m_paperMode`, and `+0x27c m_bCentered`/`m_centerText`. The `+0x26d` byte is parsed from both inbound packet formats and then cleared before common initialization; no checked evidence shows a later read in this target, so its exact business meaning remains unproven but its source role is a protocol/reserved status byte rather than an unknown behavior blocker.

Editable inbound packet opcode `0x1b` layout is: byte `+1` paper id, byte `+2` reserved/status, byte `+3` width tiles, byte `+4` height tiles, big-endian word `+5` text byte length, and text bytes at `+7`. Read-only inbound packet opcode `0x35` layout is: byte `+1` reserved/status, byte `+2` width tiles, byte `+3` height tiles, byte `+4` centered flag, big-endian word `+5` text byte length, and text bytes at `+7`. Save opcode `0x23` writes byte `+1` paper id, big-endian word `+2` text byte length, and text bytes at `+4`; the send length is text byte count plus four, while the length field is text bytes only.

Inbound display normalization converts tabs to carriage returns before inserting into the text editor. Save normalization converts carriage returns back to tabs before `WideCharToMultiByte`. The conversion paths use default ANSI code page behavior (`MultiByteToWideChar`/`WideCharToMultiByte` code page `0`, flags `0`) with local stack buffers.

`LINE001.EPD` frames `0..7` are border pieces and frame `8` is the interior/background fill tile. Frame roles are: `0` top-left, `1` top edge, `2` top-right, `3` right edge, `4` bottom-right, `5` bottom edge, `6` bottom-left, `7` left edge, and `8` fill.

The wrappers at `0x005128a0` and `0x00512900` are outside this target and should not block formal C++. They allocate `0x280`, call this constructor with mode `0` or `1`, return boolean success, and currently have no confirmed caller/pointer route. If they are later documented, place them as MapPane/paper factory wrappers such as `MapPaneCreateEditablePaperPaneWrapper` and `MapPaneCreateReadOnlyPaperPaneWrapper`, not as `EditablePaperPane` methods.
```

3. In [UID:0001EE], populate the `RECONSTRUCTION_CPP` block with the first-draft C++ from this report, or split it into method children first and place equivalent method bodies in those children. If the supervisor chooses method children, keep [UID:0001EE] as the aggregate/index with child links and route each child to [UID:000048].

4. In [UID:0000IX] `by-file/EditablePaperPane.md`, replace the current open-status paragraph that says completion stays at `86` due to wrapper and exact field/source-name blockers with:

```markdown
Completion can rise to `87` and confidence to `88` after the 2026-06-18 B003 source-quality pass. The former blockers are now bounded: `+0x26d` is a parsed-then-cleared protocol/reserved status byte with no checked target read, and `0x005128a0`/`0x00512900` are no-route MapPane-side paper factory wrappers rather than `EditablePaperPane` method bodies. Packet layouts for opcodes `0x1b`, `0x35`, and outbound save opcode `0x23`, line-break normalization, `LINE001.EPD` frame roles, vtable boundaries, and compiler-artifact exclusions are sufficient for first-draft source C++ under the active `(completion + confidence) / 2 > 85` gate.
```

5. In [UID:000048] `by-class/EditablePaperPane.md`, update the field/layout discussion with:

```markdown
Resolved tail fields: `+0x26c m_paperId`, `+0x26d m_packetStatusByte` / `m_reservedPacketStatus`, `+0x26e m_widthTiles`, `+0x26f m_heightTiles`, `+0x270 m_textLength`, `+0x278 m_paperMode`, and `+0x27c m_bCentered` / `m_centerText`. The `+0x26d` byte is read from both inbound paper packet formats and then cleared before common initialization; it is best documented as a protocol/reserved status byte, with exact business meaning unproven but no longer a source-shape blocker.

The text editor is owned through the dialog control list rather than a proven tail member. The close/action button is control index `0`, the `TextEditControlPane` is control index `1`, and save reacquires the editor from that control slot. Parser/save text buffers are local stack buffers.
```

6. In [UID:0001XF] `by-type/by-vtable/EditablePaperPaneVtables.md` and any nearby support page that still says "95/95 code gate", replace that wording with:

```markdown
Formal source C++ follows the active by-structure gate: `RECONSTRUCTABLE:TRUE`, nonblank emitter route, and `(COMPLETION + CONFIDENCE) / 2 > 85`, with names/dependencies/source placement still needing enough evidence for source-quality output. Vtable and RTTI bytes themselves remain compiler-emitted data and should not receive hand-authored C++ bodies.
```

7. In [UID:0001EF] `by-memory/0x00545ddd-0x00545df3.EditablePaperPaneAdjustorThunks.md`, no body change is required if it already states `85/90` and compiler-generated thunk disposition. Only the coverage row is stale.

8. Optional resource-doc addition if the supervisor wants a dedicated resource page later:

```markdown
`LINE001.EPD` is the editable-paper frame atlas used only by the `EditablePaperPane` border/background paths in current evidence. DrawBorder references frames `0..7` as top-left, top, top-right, right, bottom-right, bottom, bottom-left, and left border pieces. DrawBackground references frame `8` as the interior fill tile. The UTF-16 literal begins at `0x00621b98`, immediately after the tertiary `EditablePaperPane` vtable slots; `0x00621b9c` is string-byte pollution, not a LodePNG/code pointer.
```

## Coverage Report Replacement Text

Replace the [UID:0001EE] row in `by-memory/-coverage-report.md` with:

```markdown
    - [UID:0001EE][0x00545170-0x00545e3b.EditablePaperPane](by-memory/0x00545170-0x00545e3b.EditablePaperPane.md) 0x00545170-0x00545e3b | class-method aggregate | EditablePaperPane : reconstructable : 87% : strong : Source-bearing EditablePaperPane class-method aggregate with constructor mode dispatch, action handler, common content/control setup, editable opcode `0x1b` parser, read-only opcode `0x35` parser, save opcode `0x23` serializer, `LINE001.EPD` border/background renderers, packet line-break normalization, resolved tail field roles including parsed-then-cleared `+0x26d` protocol/reserved status byte, no-route MapPane-side wrapper disposition for `0x005128a0`/`0x00512900`, child adjustor-thunk exclusion, scalar-deleting destructor source policy, exact vtable-data boundary, class parent attachment, and first-draft C++ readiness under the active gate.
```

Replace the nested [UID:0001EF] row in `by-memory/-coverage-report.md` with:

```markdown
    - [UID:0001EF][0x00545ddd-0x00545df3.EditablePaperPaneAdjustorThunks](by-memory/0x00545ddd-0x00545df3.EditablePaperPaneAdjustorThunks.md) 0x00545ddd-0x00545df3 | compiler-generated thunks | EditablePaperPaneAdjustorThunks : ignored : 85% : strong : Exact secondary and tertiary `EditablePaperPane` destructor adjustor thunks; subtract `this` by `0xa0` or `0xa4` and jump to scalar deleting destructor `0x00545e00`; excluded from handwritten source while documenting vtable support evidence.
```

Do not change the [UID:0002NC] coverage row for this assignment.

## Remaining Blockers

- Fresh live IDA was unavailable during this pass. Existing live-IDA-backed documentation plus local PE scans are enough for `87/88`, but not enough for a final-audit score.
- Exact original source names for UI helper APIs are still inferred. The first-draft C++ uses descriptive helper names that must be reconciled with local `DialogPane`, `TextEditControlPane`, packet-send, and image-frame helper names before generated source can be treated as final.
- `+0x26d` exact business meaning remains unproven. Evidence checked: both parsers write it from packet data, both clear it before common initialization, no target read was found in the checked docs or generated lead, and packet layouts require the byte. Rejected alternatives: paper id, dimensions, centered flag, or persistent editor flag. Impact: no longer blocks source placement or first-draft C++, but should cap score below final-audit level.
- `0x005128a0` and `0x00512900` have no confirmed caller/pointer-table route. Evidence checked: existing B001 reports, local dword scans, local rel32 scans, and raw wrapper bytes. Impact: do not include these wrappers in [UID:0001EE] C++; keep them in MapPane no-route helper research until a route is found.
- If the supervisor requires method-level formal C++ instead of aggregate-level formal C++, create child pages for the eight source-authored methods first. This is a documentation-structure preference, not a source-quality blocker.

## Validation Commands For Supervisor

After applying the doc and coverage changes, run:

> Executable block R001 was removed from this report and preserved verbatim in [0001EE-EditablePaperPane-source-quality-removed.md](0001EE-EditablePaperPane-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Targeted review commands:

> Executable block R002 was removed from this report and preserved verbatim in [0001EE-EditablePaperPane-source-quality-removed.md](0001EE-EditablePaperPane-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

## Changed Files

This report created exactly one file:

- `tools/leaser/Agents/Agent-B003/research/0001EE-EditablePaperPane-source-quality.md`

No by-* docs, generated reports, generated source, IDA DB, source files, or `by-memory/-coverage-report.md` were modified by Agent-B003.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000004165","destination_path":"executed-b-agent-research/B003/0001EE-EditablePaperPane-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:27","uid":"0001EE"} -->
<!-- {"agent":"B003","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001EE-EditablePaperPane-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B003/0001EE-EditablePaperPane-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001EE"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
