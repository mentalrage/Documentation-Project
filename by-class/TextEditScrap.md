*** UID:0000EP | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000ON | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000EO | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:20 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class TextEditScrap;
void PutScrapToClipboard(TextEditScrap *scrap);
void GetScrapFromClipboard(TextEditScrap *scrap);

class TextEditScrap : public LObject
{
public:
    TextEditScrap();
    virtual ~TextEditScrap();

    void Clear();
    bool IsEmpty() const;
    void SetText(const wchar_t *text, int length);
    void SetPayload(const void *payload, int size);
    int DuplicateText(wchar_t **outText) const;
    int DuplicatePayload(void **outPayload) const;
    int BuildClipboardBlock(void **outBlock) const;
    void SetFromClipboardBlock(const void *data, int dataSize);

private:
    friend void GetScrapFromClipboard(TextEditScrap *scrap);

    int m_textLength;
    wchar_t *m_text;
    int m_payloadSize;
    void *m_payload;
};

typedef char TextEditScrapSizeMustBe14[
    (sizeof(TextEditScrap) == 0x14) ? 1 : -1];
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# TextEditScrap

## Status

- Current UID0000OJ incorporation: the complete declaration and exact `0x14` size assertion are formal H, not late CPP. UID0000EO inserts this authoritative class page at explicit pre-TextEditPane H position 20, after TextEditObject, under the merged UID0000ON TextEditPane source family; exact clipboard and storage method bodies remain on UID00040T and the file-local helper children.
- Confidence: very strong for layout, buffer ownership, constructor/destructor/clear/set/duplicate/import helpers, vtable identity, support-object placement, and MemoryMan helper routing; medium-high only for exact original helper spellings and the packed-text length-unit convention.
- Likely source file: [UID:0000ON][TextEditPane](by-file/TextEditPane.md)
- Main address ranges: [UID:00040T][0x00594f30-0x00595389.TextEditScrapClipboardCore](by-memory/0x00594f30-0x00595389.TextEditScrapClipboardCore.md), scalar deleting destructor `0x005956b0-0x00595759`, and restored non-deleting destructor `0x00594f70-0x00594fdf`
- Current recovered file: `source-3/simroot_v2/class_TextEditScrap.cpp`
- Formal C++: declaration-container only for the support class layout and method surface; method bodies remain on exact child pages, primarily [UID:00040T][0x00594f30-0x00595389.TextEditScrapClipboardCore](by-memory/0x00594f30-0x00595389.TextEditScrapClipboardCore.md).

## UID0000OJ Whole-File Incorporation - 2026-08-16

| Claim | Incorporated disposition |
| --- | --- |
| C0000OJ-463 | Exact `TextEditScrap` `0x14` layout/declaration moved from CPP to H. |
| C0000OJ-496 | The declaration now precedes every body use through UID0000EO's position-20 pre-class H child route rather than appearing late in generated CPP. |
| C0000OJ-506 | Complete methods, fields, clipboard friendship, and size assertion are preserved once on this authoritative formal-H page. |

## Class Purpose

`TextEditScrap` is the clipboard scrap object used by text editing. It stores copied UTF-16 text plus an optional binary/style payload, duplicates those buffers when queried, builds and imports a packed clipboard stream, converts multibyte text into UTF-16 when needed, and cleans up owned buffers on clear/destruction.

## Observed State

Important recovered state:

```text
+0x000  vtable
+0x004  text length
+0x008  text buffer pointer
+0x00c  payload size
+0x010  payload buffer pointer
```

Current source-facing names `m_textLength`, `m_textBuffer`, `m_payloadSize`, and `m_payloadBuffer` are strong enough for declaration planning and make this the most source-ready TextEdit support class. Method bodies still belong on exact child pages after allocation/copy helper names are finalized.

B011's child-level implementation resolves the allocation/copy helper question enough for first-draft C++ on [UID:00040T][0x00594f30-0x00595389.TextEditScrapClipboardCore](by-memory/0x00594f30-0x00595389.TextEditScrapClipboardCore.md). The active child draft shortens `m_textBuffer` to `m_text` and `m_payloadBuffer` to `m_payload` in code, but both naming forms refer to the same layout fields.

`TextEditScrap` owns both internal buffers. `Clear()` and the non-deleting destructor release owned text and payload storage through the MemoryMan free wrapper. `DuplicateText`, `DuplicatePayload`, and `BuildClipboardBlock` return caller-owned allocations that callers must release through the same allocation/free family.

## Method Families

| Address | Function | Role |
| --- | --- | --- |
| `0x00594f30-0x00594f67` | `TextEditScrap::TextEditScrap()` | Construct empty scrap buffer; calls [UID:00036Z][0x004f4a80-0x004f4a89.LObjectConstructor](by-memory/0x004f4a80-0x004f4a89.LObjectConstructor.md), installs vtable `0x0062e060`, and clears `+0x04/+0x08/+0x0c/+0x10`. |
| `0x00594f70-0x00594fdf` | `TextEditScrap::~TextEditScrap()` non-deleting body | Restored destructor body with compiler SEH scaffolding around real owned-buffer cleanup; chains to [UID:000370][0x004f4a90-0x004f4a97.LObjectDestructorBody](by-memory/0x004f4a90-0x004f4a97.LObjectDestructorBody.md). |
| `0x00594ff0-0x0059502f` | `Clear()` | Frees text and payload buffers and clears the matching pointer/count fields. |
| `0x00595030-0x00595043` | `IsEmpty() const` | Raw predicate returning true only when both text and payload pointers are null. |
| `0x00595050-0x00595092` | `SetText(const wchar_t* text, int length)` | Allocates `length * 2` bytes and copies UTF-16 text into owned storage. |
| `0x005950a0-0x005950d9` | `SetPayload(const void* payload, int size)` | Allocates `size` bytes and copies binary/style payload into owned storage. |
| `0x005950e0-0x00595135` | `DuplicateText(wchar_t** outText) const` | Allocates a caller-owned text copy and returns the text count, or writes null/zero when empty. |
| `0x00595140-0x00595190` | `DuplicatePayload(void** outPayload) const` | Allocates a caller-owned payload copy and returns the payload size, or writes null/zero when empty. |
| `0x005951a0-0x00595249` | `BuildClipboardBlock(void** outBlock) const` | Builds the packed clipboard block: NUL-terminated first segment, optional four-byte payload length, and payload bytes. |
| `0x00595250-0x00595389` | `SetFromClipboardBlock(const char* data, int dataSize)` | Clears current data, parses the packed clipboard stream, converts the byte text segment through `MultiByteToWideChar`, and copies any valid trailing payload. |
| `0x005956b0-0x00595759` | scalar deleting destructor | Flag-gated deleting destructor in sibling [UID:0003M8][0x005954c0-0x00595760.TextEditSupportObjectsAfterTextBoxPane](by-memory/0x005954c0-0x00595760.TextEditSupportObjectsAfterTextBoxPane.md). |

## Helper And Clipboard Stream Notes

| Address / helper | Source-facing role |
| --- | --- |
| `0x00516030` | [UID:0001BC][0x00516030-0x00516036.GetMemoryMan](by-memory/0x00516030-0x00516036.GetMemoryMan.md), MemoryMan singleton accessor used by the allocation wrapper family. |
| `0x00516050` | [UID:0001BD][0x00516050-0x005160ce.AllocateBufferMemory](by-memory/0x00516050-0x005160ce.AllocateBufferMemory.md), generic buffer allocator for text, payload, and packed block copies. |
| `0x00516170` | [UID:0001BF][0x00516170-0x00516184.FreeBufferMemory](by-memory/0x00516170-0x00516184.FreeBufferMemory.md), generic free wrapper used by destructor/clear paths. |
| `0x00516220` | [UID:0001BH][0x00516220-0x00516238.MemmoveWrapper](by-memory/0x00516220-0x00516238.MemmoveWrapper.md), copy/move wrapper used by text/payload and packed-block copies. |
| `0x0060d120` | `KERNEL32.dll!MultiByteToWideChar`, used by the packed-block importer to convert the byte text segment into UTF-16 storage. |

The packed clipboard serializer and importer are paired. `BuildClipboardBlock` writes a NUL-terminated first segment and, when payload is present, appends a four-byte payload size followed by payload bytes. `SetFromClipboardBlock` clears the current buffers, finds the NUL-terminated first segment, converts it through `MultiByteToWideChar`, and then imports a valid trailing payload. The remaining source-quality caveat is the exact length unit for `m_textLength`: regular text storage behaves like a UTF-16 code-unit count because `SetText` allocates `length * 2`, while the packed clipboard builder copies `m_textLength` bytes before the NUL terminator. The child C++ preserves this ambiguity instead of forcing a false final convention.

## UID0004T8 Clipboard Publisher Contract

- [UID:0004T8][0x005917d0-0x00591a1c.PutScrapToClipboard](by-memory/0x005917d0-0x00591a1c.PutScrapToClipboard.md) is the exact file-local `void PutScrapToClipboard(TextEditScrap *scrap)` source helper emitted by [UID:0000ON][TextEditPane](by-file/TextEditPane.md). The forward declaration/prototype is placed before this complete class so TextEditPane and UserListDialogPane source can call the helper without changing `TextEditScrap` layout or member ownership.
- The helper calls `DuplicateText` and `DuplicatePayload`, then returns immediately when duplicated text is null. A nonnull payload duplicated on that path is not freed; this observed text-null edge is preserved.
- For nonnull text it opens/empties the clipboard, expands each CR to CRLF, ACP-encodes the explicit UTF-16 length, allocates shared global memory with flag `0x2000`, writes one byte NUL, and publishes `CF_TEXT`. It preserves unchecked clipboard API results and the heap-allocated pointer Win32Error throw on global-allocation failure.
- The helper frees the original duplicated text and optional duplicated payload through MemoryMan after publication and closes the clipboard last. The payload is not published as a custom format.
- Four callers are exact: TextEditPane select-all-like, copy, and cut paths plus UID000478 UserListDialogPane selected-name Ctrl+C. The inverse reader is separately registered as UID0004U1.
- This publisher contract adds no vtable slot, data member, size change, class method body, ownership transfer, raw offset, compiler scaffolding, or broad TextEditScrap source emission.

## UID0004U1 Clipboard Reader Contract - 2026-07-20

- [UID:0004U1][0x00591a20-0x00591c65.GetScrapFromClipboard](by-memory/0x00591a20-0x00591c65.GetScrapFromClipboard.md) is the exact file-local `void GetScrapFromClipboard(TextEditScrap *scrap)` source helper emitted through UID0000ON. It is distinct from publisher UID0004T8 and is called by UID00030F paste handling.
- The helper clears prior state, reads either packed styled Unicode or CF_TEXT, removes LF units in place while preserving CR, and commits exact duplicated text/payload buffers through MemoryMan before freeing temporaries and closing the clipboard.
- Styled input is `[int textLength][UTF-16 bytes][int payloadSize][payload bytes]` without NULs or validation. CF_TEXT uses `strlen` and explicit-length `MultiByteToWideChar(CP_ACP,0,...)`. API, lock, allocation, length, and malformed-block failures remain unchecked as shipped.
- Direct writes to all four private fields are source-proven. One exact friend declaration preserves compile-legal private access without public fields, raw-offset accessors, extra setters, a member-method rewrite, or a changed allocation/copy sequence.
- Score rises only `89/90 -> 91/92`: complete reverse-reader ABI/body, private-access route, publisher/reader lifecycle, source placement, field types, negative evidence, and managed class surface are closed. Exact original private/helper spellings and the historical packed-builder length-unit caveat cap confidence.

## Evidence Notes

- `TextEditPane::OnKeyEvent` constructs local `TextEditScrap` objects on copy and cut paths.
- `TextEditPane::CopySelectionToScrap` fills the scrap from selected text and style payload.
- `TextEditPane::PasteFromClipboard` consumes a scrap when pasting text into the editor.
- [UID:0000OQ][TextPad](by-file/TextPad.md) uses `TextEditScrap` as the bridge for local `Open`/`Save` file commands: TextPad owns the outer command/file format, while this class carries the visible UTF-16 text plus optional rich payload (`m_payloadSize` / `m_payloadBuffer`) that is produced or consumed by TextEditPane serialization.
- The old memory report confirms the plain destructor was restored separately from the scalar deleting destructor.
- 2026-06-12 A004 live IDA MCP `entity_query` and `trace_data_flow` reconfirm `??_7TextEditScrap@@6B@` at `0x0062e060`, first slot `0x005956b0`, and vtable references at `0x00590563`, `0x00590593`, `0x00594f3f`, `0x00594f96`, and `0x005956dd`; exact child [UID:0003GB][0x0062e05c-0x0062e06c.TextEditScrapVtableData](by-memory/0x0062e05c-0x0062e06c.TextEditScrapVtableData.md) is now split and routed here.
- 2026-06-21 B011 Rule 26 incorporation created [UID:00040T][0x00594f30-0x00595389.TextEditScrapClipboardCore](by-memory/0x00594f30-0x00595389.TextEditScrapClipboardCore.md) as the exact direct class-method child for the constructor, non-deleting destructor body, clear/test helpers, copy/duplicate helpers, packed serializer, and importer/converter.
- B011 direct-call evidence confirms constructor callers at `0x004ff0d8`, `0x004ff498`, `0x00590ae5`, `0x00590b7d`, `0x00590c4b`, `0x00595c33`, `0x00595d59`, `0x00595f67`, `0x005960a4`, and `0x0059d9f8`; destructor callers at `0x004ff257`, `0x004ff617`, `0x00590b4e`, `0x00590c2a`, `0x00590c71`, `0x00595d1c`, `0x00595e60`, `0x0059604c`, `0x005961af`, and `0x0059da43`; and helper callers for `Clear`, `SetText`, `DuplicateText`, `DuplicatePayload`, and `SetFromClipboardBlock`.
- The child range ends at `0x00595389`; `0x00595389-0x00595390` is seven `0xcc` bytes before [UID:0002RV][0x00595390-0x005954b3.TextBoxPaneConstructor](by-memory/0x00595390-0x005954b3.TextBoxPaneConstructor.md).
- 2026-06-30 B004 corrected TextEditPane implementation callback preserves the current `TextEditScrap` disposition for [UID:0000ON][TextEditPane](by-file/TextEditPane.md): the support class uses the text/payload buffer layout at `+0x04/+0x08/+0x0c/+0x10`, not a rectangle/draw-object shape. The declaration now uses the current first-draft names `m_text`, `m_payload`, `DuplicateText`, `DuplicatePayload`, `BuildClipboardBlock`, and `SetFromClipboardBlock`, while the packed length-unit caveat remains active.

## Cross-References

- [UID:0000ON][TextEditPane](by-file/TextEditPane.md)
- [UID:0000EO][TextEditPane](by-class/TextEditPane.md)
- [UID:00040T][0x00594f30-0x00595389.TextEditScrapClipboardCore](by-memory/0x00594f30-0x00595389.TextEditScrapClipboardCore.md)
- [UID:0001JT][0x00594e60-0x005958fe.TextEditSupportObjectsAndFilter](by-memory/0x00594e60-0x005958fe.TextEditSupportObjectsAndFilter.md)
- [UID:0003M7][0x00594e60-0x00595389.TextEditSupportObjectsBeforeTextBoxPane](by-memory/0x00594e60-0x00595389.TextEditSupportObjectsBeforeTextBoxPane.md)
- [UID:0003M8][0x005954c0-0x00595760.TextEditSupportObjectsAfterTextBoxPane](by-memory/0x005954c0-0x00595760.TextEditSupportObjectsAfterTextBoxPane.md)
- [UID:0003GB][0x0062e05c-0x0062e06c.TextEditScrapVtableData](by-memory/0x0062e05c-0x0062e06c.TextEditScrapVtableData.md)
- [UID:0001BC][0x00516030-0x00516036.GetMemoryMan](by-memory/0x00516030-0x00516036.GetMemoryMan.md)
- [UID:0001BD][0x00516050-0x005160ce.AllocateBufferMemory](by-memory/0x00516050-0x005160ce.AllocateBufferMemory.md)
- [UID:0001BF][0x00516170-0x00516184.FreeBufferMemory](by-memory/0x00516170-0x00516184.FreeBufferMemory.md)
- [UID:0001BH][0x00516220-0x00516238.MemmoveWrapper](by-memory/0x00516220-0x00516238.MemmoveWrapper.md)
- [UID:0004T8][0x005917d0-0x00591a1c.PutScrapToClipboard](by-memory/0x005917d0-0x00591a1c.PutScrapToClipboard.md)
- [UID:000478][0x0059d900-0x0059da82.UserListDialogPaneHandleKeyOrTextEvent](by-memory/0x0059d900-0x0059da82.UserListDialogPaneHandleKeyOrTextEvent.md)

## Changes

- 2026-08-22 Agent-B009 UID0000OJ Gate 2A repair: set explicit H child position 20 under UID0000EO so this page is the sole TextEditScrap definition, follows TextEditObject, and precedes TextEditPane in generated H.

- 2026-07-20 B005 UID000478 accepted implementation callback, Phase 2:
  - Preserved `89/90`, owner/emitter UID0000ON, reconstructable state, blank optional position, complete four-field layout, constructor/destructor/Clear/set/duplicate/packed-block methods, child-body ownership, MemoryMan/TextPad/B001/B003/B004 evidence, length-unit caveat, and all history.
  - Applied Destination 5 exactly by adding only the compile-visible `TextEditScrap` forward declaration and `void PutScrapToClipboard(TextEditScrap *scrap)` prototype before the unchanged complete class declaration.
  - Added validator-issued UID0004T8 source/caller/duplicate/CRLF/ACP/CF_TEXT/failure/cleanup/text-null/payload/paired-reader evidence without changing class layout, method ownership, route, or score.
- 2026-06-30 B004 corrected TextEditPane implementation callback:
  - Before: score `88/90`; the page documented the text/payload layout and helper family but kept the class declaration blank during the earlier TextEditObject/TextEditScrap support-order dispute.
  - Changed to: score `89/90`; inserted a declaration-container-only formal C++ block for the support class, using the current text/payload buffer fields and helper names. Method bodies remain owned by exact memory children, especially [UID:00040T][0x00594f30-0x00595389.TextEditScrapClipboardCore](by-memory/0x00594f30-0x00595389.TextEditScrapClipboardCore.md).
  - Evidence: the revised B004 [UID:0000ON][TextEditPane](by-file/TextEditPane.md) report rejected the stale rectangle/bounds support disposition and reconfirmed this page's current `m_textLength`/`m_text`/`m_payloadSize`/`m_payload` layout, constructor/destructor/clear/set/duplicate/packed-clipboard helper family, and remaining packed length-unit caveat.

- 2026-06-21 B011 Rule 26 split incorporation:
  - Before: `87/89`, with layout and high-level method families documented but no exact direct method child or full helper/packed-stream closure.
  - After: `88/90`; added [UID:00040T][0x00594f30-0x00595389.TextEditScrapClipboardCore](by-memory/0x00594f30-0x00595389.TextEditScrapClipboardCore.md), expanded method names and ranges, documented buffer ownership, MemoryMan helper aliases, packed clipboard stream behavior, direct caller routes, scalar-deleting destructor placement, and first-draft child C++ readiness.
  - Evidence: B011 local PE/range reanalysis, existing vtable docs, MemoryMan helper docs, import/call shape for `MultiByteToWideChar`, and TextEditPane/TextPad caller routes support the score increase while preserving the packed length-unit caveat.

- Before: reconstruction autogen metadata was unclassified.
- Changed to: marked `RECONSTRUCTABLE:TRUE` and attached to [UID:0000ON][TextEditPane](by-file/TextEditPane.md).
- Evidence: 2026-06-05 IDA MCP on `NexusTK.exe` (`md5 4247e04e20b65d6414c7238aa8ff5515`) confirmed the documented scrap constructor, destructor, clear, set, get, multibyte-conversion, and scalar deleting destructor starts at `0x00594f30`, `0x00594f70`, `0x00594ff0`, `0x00595050`, `0x005950e0`, `0x00595250`, and `0x005956b0`; this page and parent [UID:0000ON][TextEditPane](by-file/TextEditPane.md) both meet the 80/80 parent gate. No C++ was emitted because the page is below the 95/95 reconstruction-code bar.
- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `86`, confidence `88`.
- Evidence: the page documents clipboard-scrap role, layout, constructor/destructor/clear/set/get/convert/scalar-destructor methods, and usage from copy/cut/paste paths; remaining completion gap is source-ready C++ detail.
- 2026-06-12 A004 Batch 277:
  - Before: `COMPLETION:86`, `CONFIDENCE:88`.
  - After: `COMPLETION:87`, `CONFIDENCE:89`; parent remains [UID:0000ON][TextEditPane](by-file/TextEditPane.md).
  - Evidence: live IDA MCP reconfirmed the exact vtable child, scalar-deleting-destructor first slot, text-edit temporary scrap xrefs, constructor/destructor vtable stores, and owner-code boundaries. The exact vtable child [UID:0003GB][0x0062e05c-0x0062e06c.TextEditScrapVtableData](by-memory/0x0062e05c-0x0062e06c.TextEditScrapVtableData.md) is now assigned here.

- 2026-06-20 B005 Rule 26 source-quality incorporation:
  - Score unchanged at `87/89`; final C++ remains blank.
  - Recorded that `m_textLength`, `m_textBuffer`, `m_payloadSize`, and `m_payloadBuffer` are the current source-facing layout names and that `TextEditScrap` is the most source-ready support class in this cluster.
  - Evidence: B005 report confirmed this layout is already present at high specificity and should be preserved under [UID:0000ON][TextEditPane](by-file/TextEditPane.md).
- 2026-06-21 B008 TextPad source-quality sync:
  - Score unchanged at `87/89`.
  - Added the TextPad `Open`/`Save` dependency note: TextPad owns the local file command route, while `TextEditScrap` remains the TextEditPane-owned carrier for visible text and optional rich payload.
