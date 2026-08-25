*** UID:0000AC | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000MH | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000MH | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:10 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class PatchPane::PatchFileSlice {
    friend class PatchPane;

public:
    PatchFileSlice();
    virtual ~PatchFileSlice();

private:
    bool m_requestIssued;
    unsigned int m_payloadLength;
    unsigned char *m_payloadData;
};
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# PatchPane::PatchFileSlice

## Status

- Confidence: very strong for PatchPane ownership, constructor/destructor pairing, vtable identity, and field roles; medium-high for exact original member spellings.
- Likely source file: [UID:0000MH][PatchPane](by-file/PatchPane.md)
- Current generated-output caveat: the deleting-destructor path is represented elsewhere, but live IDA evidence shows the constructor and non-deleting destructor must also be documented for source reconstruction.
- Memory range: [UID:0001EQ][0x005470b0-0x0054940f.PatchPaneAndPatchPane2](by-memory/0x005470b0-0x0054940f.PatchPaneAndPatchPane2.md)
- 2026-06-15 live IDA status: current `NexusTK.exe` session reconfirms constructor `sub_5483A0` size `0x1b`, non-deleting destructor `sub_548410` size `0x15`, vector deleting destructor `sub_548430` size `0xab`, unique signature for the `0x005483a0-0x005484db` slice cluster, vtable `0x00621dbc` refs from all three bodies, and iterator/vtable references from the packet response handler.

## Class Purpose

`PatchPane::PatchFileSlice` stores one patch-entry download slice owned by the PatchPane packet/update flow. The object keeps a vtable, a request-issued byte, a payload byte length, and a payload pointer that is freed during destruction.

The enclosing `PatchPane` handler writes the slice fields directly while processing subtype `1` patch responses, so the first-draft declaration grants `PatchPane` friendship rather than making the fields public. This keeps the source shape close to a small nested support class while allowing `PatchPane::HandlePatchResponsePacket` and `PatchPane::SendPendingPatchEntryRequests` to match the observed field writes.

## Layout

`PatchPane::PatchFileSlice` is a `0x10`-byte vector element. The element has a one-slot vtable and a virtual destructor, so the first dword is the vptr for `0x00621dbc`.

| Offset | Recommended member | Type | Evidence |
| --- | --- | --- | --- |
| `+0x00` | vptr | compiler vptr | Constructor, non-deleting destructor, and vector deleting destructor install `0x00621dbc`; [UID:0002OI][0x00621db8-0x00621e64.PatchPaneVtableData](by-memory/0x00621db8-0x00621e64.PatchPaneVtableData.md) identifies the one-slot `PatchFileSlice` vtable. |
| `+0x04` | `m_requestIssued` | `bool` | Cleared by the constructor; `PatchPane::SendPendingPatchEntryRequests` sends entries only when this byte is `0` and `m_payloadData` is null, then writes it to `1`; the in-flight count checks `m_requestIssued == 1 && m_payloadData == 0`. |
| `+0x08` | `m_payloadLength` | `unsigned int` | Cleared by the constructor; subtype `1` patch response stores the received payload byte length here before allocating and copying payload bytes. |
| `+0x0c` | `m_payloadData` | `unsigned char *` | Cleared by the constructor; subtype `1` receive path stores allocated payload storage here, completion scanning counts non-null pointers, and the destructor frees this pointer. |

## Method Notes

| Range | Method | Notes |
| --- | --- | --- |
| `0x005483a0-0x005483bb` | [UID:0001ES][0x005483a0-0x005483bb.PatchFileSliceConstructor](by-memory/0x005483a0-0x005483bb.PatchFileSliceConstructor.md) | Installs the vtable and clears `m_requestIssued`, `m_payloadLength`, and `m_payloadData`; now has first-draft nested-class constructor C++. |
| `0x00548410-0x00548425` | [UID:0001ET][0x00548410-0x00548425.PatchFileSliceDestructor](by-memory/0x00548410-0x00548425.PatchFileSliceDestructor.md) | Reinstalls the vtable, frees `m_payloadData` when non-null, and leaves storage ownership to the vector/deleting path; now has first-draft nested-class destructor C++. |
| `0x00548430-0x005484db` | vector/scalar deleting destructor | Compiler-generated deleting destructor body for the one-slot vtable; handles single-object and array destruction, frees payload buffers, and optionally frees storage. The old `0x00548430-0x005484da` wording was a last-instruction-byte endpoint rather than the project half-open end. |

## Evidence Notes

- IDA MCP decompilation of `0x005474f0` shows vector construction of `PatchFileSlice` entries using `0x005483a0` and `0x00548410`; A009 2026-06-06 refresh confirms the `eh vector constructor iterator` uses 0x10-byte elements and pairs constructor `0x005483a0` with destructor `0x00548410`.
- Constructor callback xref evidence places `0x005483a0` at `0x005477e4` inside `PatchPanePacketResponseHandler`, where the slice array is constructed.
- The constructor installs the `PatchPane::PatchFileSlice` vtable, clears `m_requestIssued` at `+0x04`, clears `m_payloadLength` at `+0x08`, and clears `m_payloadData` at `+0x0c`.
- The non-deleting destructor reinstalls the same vtable and frees `m_payloadData` at `+0x0c` if present; storage ownership is left to the vector/deleting-destructor path.
- B003's 2026-06-18 source-quality pass rejects stale `m_complete`, `m_received`, `m_done`, `m_index`, and generic `stateByte`/`payload pointer` names. The request byte is set after sending a request and is not cleared on receipt; the packet entry index is used only to choose `sliceBase + index * 0x10`, not stored in the element; and completion is based on `m_payloadData != 0`.
- B008's 2026-06-27 [UID:0001ER][0x005474f0-0x00547850.PatchPanePacketResponseHandler](by-memory/0x005474f0-0x00547850.PatchPanePacketResponseHandler.md) implementation confirms the consumer side of those fields: subtype `1` writes `m_payloadLength`, allocates and writes `m_payloadData`, scans `m_payloadData != NULL` for progress, and leaves `m_requestIssued` to [UID:0000A9][PatchPane](by-class/PatchPane.md)'s pending-entry sender. The class declaration uses `friend class PatchPane;` so the enclosing handler can write private slice fields without exposing them as public API.
- A009 2026-06-06 IDA MCP caller/callee refresh reports no ordinary direct callers for the constructor or non-deleting destructor; the constructor has no callees, while the destructor calls only `j_j_j___free_base`.
- [UID:0002OI][0x00621db8-0x00621e64.PatchPaneVtableData](by-memory/0x00621db8-0x00621e64.PatchPaneVtableData.md) records the RTTI at `0x00621db8`, the one-slot vtable at `0x00621dbc`, and the slot target `0x00548430`.
- The vtable-data boundary ends before the `Auto Patch` string at `0x00621e64`, so the slice RTTI/vtable data is separated from later PatchPane read-only strings.
- [UID:0001YF][PatchPaneVtableFamily](by-type/by-vtable/PatchPaneVtableFamily.md) confirms the `PatchFileSlice` vtable at `0x00621dbc` with only the vector/scalar deleting destructor slot.
- 2026-06-15 live IDA recheck:
  - `lookup_funcs` reports the three modeled slice methods at `0x005483a0`, `0x00548410`, and `0x00548430`; `0x00621dbc` is data, not a function.
  - `make_signature_for_range 0x005483a0-0x005484db` returns `unique:true`.
  - `xrefs_to` reports constructor/destructor iterator data refs from `sub_5474F0`, the destructor reference from the vector deleting destructor at `0x0054845f`, the vector deleting destructor slot at `0x00621dbc`, and vtable refs from all three slice methods.
  - `analyze_component` reports the constructor has no callees, the non-deleting destructor calls only `j_j_j___free_base`, and the vector deleting destructor calls vector-delete/free helpers.
- 2026-06-18 B003 raw PE/Capstone recheck: `0x00548430-0x005484db` is the exact compiler-generated MSVC deleting-destructor body. It uses delete flags, a count header for array deletion, 0x10-byte elements, non-deleting destructor callback `0x00548410`, vector destructor/free helpers, and no separate handwritten source body beyond `virtual ~PatchFileSlice()`.
- [UID:0003OC][0x00548500-0x00548555.PatchFileDataScalarDeletingDestructor](by-memory/0x00548500-0x00548555.PatchFileDataScalarDeletingDestructor.md) independently corroborates the array contract from the owner side: `PatchFileData::m_patchEntrySlices` points past the same four-byte element-count cookie to these exact `0x10`-byte elements, and `PatchFileData::~PatchFileData()` destroys the array with `delete[]`.

## Autogen Status

- Reconstructable: true. The nested class owner, constructor, destructor, deleting destructor, and one-slot vtable are now corroborated by the PatchPane file page, memory pages, and vtable family page.
- Parent: [UID:0000MH][PatchPane](by-file/PatchPane.md). The parent file has a valid proposed path and sufficient score for child attachment.
- Code: first-draft class declaration is present. The names `m_requestIssued`, `m_payloadLength`, and `m_payloadData` are high-probability descriptive names based on packet-handler data flow, not proven original identifiers. The vector/scalar deleting destructor remains no-code because the compiler regenerates it from the virtual destructor declaration.

## Score Rationale

- Completion is raised to 88 because the class purpose, parent, memory ranges, vector construction/destruction path, constructor/destructor behavior, vtable evidence, current IDA unique signature, caller/callee/xref refresh, 0x10-byte layout, resolved field roles, deleting-destructor policy, and draft class declaration are documented.
- Confidence is raised to 91 because ownership by PatchPane, nested-class identity, exact method ranges, vector iterator use, vtable metadata, and field roles are mutually supported by target pages, packet-handler data flow, raw bytes, and current IDA evidence. Remaining uncertainty is exact original identifier spelling.

## Cross-References

- [UID:0000MH][PatchPane](by-file/PatchPane.md)
- [UID:0000A9][PatchPane](by-class/PatchPane.md)
- [UID:0001YF][PatchPaneVtableFamily](by-type/by-vtable/PatchPaneVtableFamily.md)
- [UID:0002OI][0x00621db8-0x00621e64.PatchPaneVtableData](by-memory/0x00621db8-0x00621e64.PatchPaneVtableData.md)
- [UID:0001EQ][0x005470b0-0x0054940f.PatchPaneAndPatchPane2](by-memory/0x005470b0-0x0054940f.PatchPaneAndPatchPane2.md)
- [UID:0001ES][0x005483a0-0x005483bb.PatchFileSliceConstructor](by-memory/0x005483a0-0x005483bb.PatchFileSliceConstructor.md)
- [UID:0001ET][0x00548410-0x00548425.PatchFileSliceDestructor](by-memory/0x00548410-0x00548425.PatchFileSliceDestructor.md)

## Changes

- Before: completion/confidence metadata were `0/0` even though the page documented the nested slice object, constructor/destructor/vector deleting destructor, and Wave3 omission.
- Changed to: `COMPLETION:70` and `CONFIDENCE:72`.
- Evidence: constructor, non-deleting destructor, vector deleting destructor, payload pointer cleanup, `PatchPane` packet-handler construction evidence, and vtable slot are documented; remaining gaps are field names, complete layout, and active generated-source coverage.
- 2026-06-02: Raised to `76/84`, marked reconstructable, attached to [UID:0000MH][PatchPane](by-file/PatchPane.md), and added constructor callback, offset-state, destructor cleanup, vtable-data, and scoring rationale evidence. C++ remains blank pending final member names.
- 2026-06-06 A009: Raised to `80/88`, removed generated-source wording as authority, and synchronized the class summary with current IDA evidence from the constructor/destructor pages: 0x10-byte vector-constructor elements, no ordinary direct callers for the paired helpers, no constructor callees, destructor free-base callee, and PatchPane file-parent attachment.
- 2026-06-15 A002 Goal 2 by-class refresh: raised to `86/89` after live IDA reconfirmed all three slice method sizes, the data vtable at `0x00621dbc`, unique cluster signature, packet-handler iterator refs, vtable refs from constructor/destructor/vector-deleting destructor, and callee shapes. Owner/emitter route remains [UID:0000MH][PatchPane](by-file/PatchPane.md); final C++ remains blank pending final member names and source-quality layout semantics.
- 2026-06-18 B003 source-quality execution: raised from `86/89` to `88/91`, resolved the 0x10-byte layout as `vptr`, `m_requestIssued`, `m_payloadLength`, and `m_payloadData`, corrected the vector/scalar deleting destructor half-open range to `0x00548430-0x005484db`, recorded why the deleting destructor should be ignored rather than emitted, and added first-draft nested class declaration C++.
- 2026-06-27 B008 PatchPane handler support sync: score unchanged at `88/91`; added `friend class PatchPane;` to the first-draft declaration and recorded that [UID:0001ER][0x005474f0-0x00547850.PatchPanePacketResponseHandler](by-memory/0x005474f0-0x00547850.PatchPanePacketResponseHandler.md) directly consumes `m_payloadLength` and `m_payloadData` while `SendPendingPatchEntryRequests` owns `m_requestIssued`.
- 2026-08-25 B006 UID0003OC support sync: score and formal class unchanged at `88/91`; added the nested owner's scalar-deleting-destructor corroboration for the four-byte cookie, exact `0x10` element size, and `delete[]` lifetime. Set emitter position `10` so this complete element type precedes `PatchFileData` in `PatchPane.cpp`.
