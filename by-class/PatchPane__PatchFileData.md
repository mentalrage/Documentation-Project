*** UID:0000AB | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000MH | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000MH | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:20 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class PatchPane::PatchFileData {
    friend class PatchPane;

public:
    PatchFileData()
        : m_patchEntryCount(0),
          m_patchEntrySlices(0)
    {
        m_currentPatchName[0] = L'\0';
    }

    virtual ~PatchFileData()
    {
        delete[] m_patchEntrySlices;
        m_patchEntrySlices = 0;
    }

private:
    wchar_t m_currentPatchName[256];
    int m_patchEntryCount;
    PatchFileSlice *m_patchEntrySlices;
};
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# PatchPane::PatchFileData

## Status

- Confidence: very strong for nested `PatchPane` ownership, exact `0x20c` layout, packet-handler producer, standard `PatchFileSlice[]` ownership, virtual destructor, and one-slot vtable identity. The only remaining uncertainty is the descriptive outer-member spelling `m_patchFileData`.
- Likely source file: [UID:0000MH][PatchPane](by-file/PatchPane.md)
- Generated-output reference: legacy generated output had a standalone `class_PatchPane__PatchFileData.cpp`; reconstruction should keep this as a nested `PatchPane` support type.
- Memory range: [UID:0001EQ][0x005470b0-0x0054940f.PatchPaneAndPatchPane2](by-memory/0x005470b0-0x0054940f.PatchPaneAndPatchPane2.md)

## Class Purpose

`PatchPane::PatchFileData` is the embedded nested owner for one patch-script name, its entry count, and an owning `PatchFileSlice[]` array in the startup patch/update subsystem. `PatchPane` constructs this `0x20c` subobject in place at outer offset `+0x26c`, so its fields appear at outer offsets `+0x270`, `+0x470`, and `+0x474`. The nested object is composition, not a PatchPane base: PatchPane RTTI does not list it among the seven bases, while PatchFileData has a separate one-base hierarchy descriptor.

## Rebuild Handling

- Reconstructability: true for the nested type declaration and scalar deleting destructor behavior.
- Parent handling: attach under [UID:0000MH][PatchPane](by-file/PatchPane.md), which already owns `PatchPane`, `PatchPane2`, and the nested patch-file support types at `92/94` with the family source route resolved.
- C++ handling: emit the exact nested class in this CPP block. The constructor initializes the first name character, count, and slice pointer; the virtual destructor uses `delete[] m_patchEntrySlices;` followed by `m_patchEntrySlices = 0;`, which regenerates UID0003OC and the compiler vtable/RTTI artifacts.
- H handling: keep the H block blank under the established sibling nested-class convention. The outer PatchPane declaration supplies the nested declaration context; this page must not invent a standalone header fragment.
- Source order: emit the complete [UID:0000AC][PatchPane__PatchFileSlice](by-class/PatchPane__PatchFileSlice.md) class before `PatchFileData`, because `delete[]` requires a complete element type at destructor compilation.
- Binary handling: do not emit the vtable data directly. [UID:0002OI][0x00621db8-0x00621e64.PatchPaneVtableData](by-memory/0x00621db8-0x00621e64.PatchPaneVtableData.md) is compiler-emitted evidence that should be regenerated from the final nested type declaration.

## Method Notes

| Range | Method | Notes |
| --- | --- | --- |
| [UID:0003OC][0x00548500-0x00548555.PatchFileDataScalarDeletingDestructor](by-memory/0x00548500-0x00548555.PatchFileDataScalarDeletingDestructor.md) | scalar deleting destructor | Compiler-generated from the virtual destructor; performs standard `delete[]` cleanup of `m_patchEntrySlices` at `+0x208`, clears the pointer, and optionally frees the `0x20c` object when flag bit `0` is set. |

## Exact Layout

| Nested offset | Outer PatchPane offset | Source-facing field | Evidence |
| --- | --- | --- | --- |
| `+0x00` | `+0x26c` | compiler vptr | Constructor `0x00547119`, owner teardown, UID0003OC, and PatchPane scalar teardown install `0x00621dc4`. |
| `+0x04` | `+0x270` | `wchar_t m_currentPatchName[256]` | Constructor clears the first wide character; packet/reset paths compare/copy the fixed name. The 512-byte array ends at nested `+0x203`. |
| `+0x204` | `+0x470` | `int m_patchEntryCount` | Constructor clears it; subtype `0` stores the packet count; request/receive/write/delete paths bound array traversal with it. |
| `+0x208` | `+0x474` | `PatchFileSlice *m_patchEntrySlices` | Constructor clears it; subtype `0` stores the counted element pointer; consumers index `0x10`-byte slices; cleanup performs `delete[]` and clears it. |

Total size is exactly `0x20c`. The source-facing names are descriptive/inferred rather than PDB-recovered. `m_currentPatchName`, `m_patchEntryCount`, and `m_patchEntrySlices` are established by current formal PatchPane source and behavior; `m_patchFileData` is the recommended descriptive name for the outer embedded member.

## Producer And Lifetime

- Subtype `0` of [UID:0001ER][0x005474f0-0x00547850.PatchPanePacketResponseHandler](by-memory/0x005474f0-0x00547850.PatchPanePacketResponseHandler.md) stores the big-endian count, overflow-guards `count * 0x10 + 4`, allocates through the operator-new path, writes the four-byte MSVC array cookie, advances to `base+4`, runs the vector constructor iterator with element size `0x10`, constructor `0x005483a0`, and destructor callback `0x00548410`, then stores the element pointer.
- Subtype `1` fills the selected slice's payload length/data and scans the array for completion. `0x00547b70` schedules at most four pending requests through `m_requestIssued`; `0x00547e10` writes payload buffers; `0x00547a60` resets a script and releases an old array.
- PatchPane ordinary/scalar teardown and UID0003OC all address the same embedded subobject and array field. The count-zero direct free is compiler handling for an empty array cookie, not a custom ownership scheme.
- Source cleanup is exactly `delete[] m_patchEntrySlices;` followed by `m_patchEntrySlices = 0;`; the unconditional store at `0x00548534` proves the explicit second assignment. Do not hand-author the compiler-only cookie read, vector loop, virtual deleting-destructor call, or optional scalar object free.

## Data And Vtable Evidence

- [UID:0002OI][0x00621db8-0x00621e64.PatchPaneVtableData](by-memory/0x00621db8-0x00621e64.PatchPaneVtableData.md) records `PatchPane::PatchFileData` as a one-slot nested vtable at `0x00621dc4`.
- The preceding RTTI dword at `0x00621dc0` points to `??_R4PatchFileData@PatchPane@@6B@`, which ties the vtable identity to the nested `PatchPane` type.
- The only vtable slot at `0x00621dc4` targets `0x00548500`, matching the scalar deleting destructor documented here.
- [UID:0001YF][PatchPaneVtableFamily](by-type/by-vtable/PatchPaneVtableFamily.md) includes `PatchPane::PatchFileData` between `PatchFileSlice` and the main `PatchPane` vtable family, matching the source nesting described by [UID:0000MH][PatchPane](by-file/PatchPane.md).
- [UID:000264][0x00621db8-0x00622030.PatchPaneReadOnlyData](by-memory/0x00621db8-0x00622030.PatchPaneReadOnlyData.md) keeps the surrounding `.rdata` aggregate source-declared/generated-binary rather than a hand-ported data blob.

## Evidence Notes

- `PatchPane` constructor/destructor paths in [UID:0001EQ][0x005470b0-0x0054940f.PatchPaneAndPatchPane2](by-memory/0x005470b0-0x0054940f.PatchPaneAndPatchPane2.md) are the executable owner for this nested helper, and the aggregate now keeps [UID:0003OC][0x00548500-0x00548555.PatchFileDataScalarDeletingDestructor](by-memory/0x00548500-0x00548555.PatchFileDataScalarDeletingDestructor.md) between the `PatchFileSlice` vector deleting destructor and `PatchPane` scalar deleting destructor.
- 2026-06-14 C001 IDA MCP confirms `lookup_funcs 0x00548500` size `0x55`, so the correct project half-open range is `0x00548500-0x00548555`; byte evidence shows the `retn 4` at last byte `0x00548554` and padding beginning at `0x00548555`.
- The same live pass confirms the one-slot vtable xref `0x00621dc4 -> 0x00548500`, table-base stores from the PatchPane constructor/destructor paths, the `+0x208` backing-store cleanup, and optional object delete through the shared delete helper.
- The helper is too tightly coupled to patch entry state to be a standalone original source file; it is an embedded `PatchPane` member and emits through `NexusTK/patch/PatchPane.cpp`.
- [UID:0001YF][PatchPaneVtableFamily](by-type/by-vtable/PatchPaneVtableFamily.md) confirms the `PatchFileData` vtable at `0x00621dc4` with only the scalar deleting destructor slot.
- [UID:0002OI][0x00621db8-0x00621e64.PatchPaneVtableData](by-memory/0x00621db8-0x00621e64.PatchPaneVtableData.md) confirms exact neighboring boundaries: `PatchFileSlice` at `0x00621dbc`, `PatchFileData` at `0x00621dc4`, `PatchPane` primary at `0x00621dcc`, and the string boundary at `0x00621e64`.
- [UID:0000AC][PatchPane__PatchFileSlice](by-class/PatchPane__PatchFileSlice.md) provides the exact `0x10` element declaration used by this class's counted array.
- 2026-08-25 B006 live canonical MCP recheck resolved the formerly open producer and layout: fixed in-place construction at outer `+0x26c`, fields at nested `+0x04/+0x204/+0x208`, exact `0x20c` size, packet-handler `new[]` producer, four-byte cookie, slice callbacks, consumers, and owner teardown all agree.

## Reconstruction Notes

- Model this as a nested `PatchPane::PatchFileData` support object, not as an independent patch module class.
- Preserve the exact class layout and descriptive-name caveat; do not flatten these fields into direct PatchPane members in source.
- Use `PatchFileData m_patchFileData` as the inferred outer composition and qualify affected PatchPane field accesses through it.
- Keep this H block blank only under the documented nested-class convention. The formal CPP is final first-draft source and must follow the complete PatchFileSlice declaration.
- Do not emit the scalar deleting helper, vtable, RTTI, array cookie, runtime allocation iterators, or any standalone data island as handwritten source.

## Score Rationale

- Completion is `92` because nested ownership, exact `0x20c` layout, constructor state, packet producer, array cookie, exact element declaration, all major consumers, delete-array lifetime, vtable/RTTI handling, source order, formal CPP, and blank-H proof are implementation-ready.
- Confidence is `94` because constructor/destructor offsets, producer arithmetic/callbacks, slice layout, consumer indexing, owner teardown, target bytes, and decorated vtable/RTTI independently agree. It remains below 100 only because the outer member spelling is descriptive rather than symbol-proven.

## Cross-References

- [UID:0000MH][PatchPane](by-file/PatchPane.md)
- [UID:0000A9][PatchPane](by-class/PatchPane.md)
- [UID:0001YF][PatchPaneVtableFamily](by-type/by-vtable/PatchPaneVtableFamily.md)
- [UID:0002OI][0x00621db8-0x00621e64.PatchPaneVtableData](by-memory/0x00621db8-0x00621e64.PatchPaneVtableData.md)
- [UID:000264][0x00621db8-0x00622030.PatchPaneReadOnlyData](by-memory/0x00621db8-0x00622030.PatchPaneReadOnlyData.md)
- [UID:0001EQ][0x005470b0-0x0054940f.PatchPaneAndPatchPane2](by-memory/0x005470b0-0x0054940f.PatchPaneAndPatchPane2.md)
- [UID:0003OC][0x00548500-0x00548555.PatchFileDataScalarDeletingDestructor](by-memory/0x00548500-0x00548555.PatchFileDataScalarDeletingDestructor.md)

## Changes

- Before: completion/confidence metadata were `0/0` despite the page identifying this as a nested patch backing-storage object with a known scalar deleting destructor.
- Changed to: `COMPLETION:62` and `CONFIDENCE:68`.
- Evidence: destructor behavior, backing-store pointer release, vtable slot, and tight ownership by `PatchPane` are documented; completion and confidence remain moderate because only one emitted method is understood and the full nested layout/lifetime semantics are not yet reconstructed.
- 2026-06-02:
  - Before: the page remained in the low-both queue and was not attached to the confirmed patch source file.
  - After: raised to `74/82`, marked `RECONSTRUCTABLE:TRUE`, and attached to [UID:0000MH][PatchPane](by-file/PatchPane.md).
  - Summary/evidence: `PatchPane` file ownership, exact vtable child [UID:0002OI][0x00621db8-0x00621e64.PatchPaneVtableData](by-memory/0x00621db8-0x00621e64.PatchPaneVtableData.md), vtable-family slot evidence, and the real destructor at `0x00548500` support nested-source reconstruction while keeping final C++ blank.
- 2026-06-07 A004:
  - Before: the page was attached and had the key destructor/vtable evidence, but still carried stale score history and did not explain the sibling `PatchFileSlice` comparison, `.rdata` rebuild handling, or why confidence stays below final/source-emission quality.
  - After: raised to `80/86`, clarified nested-source handling, expanded evidence and reconstruction notes, added score rationale, and cross-linked the read-only-data aggregate.
  - Summary/evidence: [UID:0000MH][PatchPane](by-file/PatchPane.md) owns the patch subsystem, [UID:0001EQ][0x005470b0-0x0054940f.PatchPaneAndPatchPane2](by-memory/0x005470b0-0x0054940f.PatchPaneAndPatchPane2.md) places the nested destructor in the patch-pane executable island, [UID:0002OI][0x00621db8-0x00621e64.PatchPaneVtableData](by-memory/0x00621db8-0x00621e64.PatchPaneVtableData.md) records the one-slot nested vtable/RTTI identity, and [UID:0000AC][PatchPane__PatchFileSlice](by-class/PatchPane__PatchFileSlice.md) provides the current nested-helper documentation pattern.
- 2026-06-14 C001 Goal 2 exact-child refresh:
  - Before: `80/86`, with the destructor summarized using stale last-byte endpoint `0x00548554`.
  - After: `85/88`, added exact child [UID:0003OC][0x00548500-0x00548555.PatchFileDataScalarDeletingDestructor](by-memory/0x00548500-0x00548555.PatchFileDataScalarDeletingDestructor.md), corrected the half-open endpoint, and added live IDA 9.1 function-size/xref/decompiler/byte evidence. Owner/emitter routing remains [UID:0000MH][PatchPane](by-file/PatchPane.md); final C++ remains blank because producer/allocation semantics and final field names are not source-quality.
- 2026-08-25 B006 accepted UID0003OC implementation callback:
  - Raised from `85/88` to `92/94`, emitted the exact nested-class CPP, preserved blank H under the sibling convention, and resolved the embedded `+0x26c` / size `0x20c` topology.
  - Added exact fields, packet-handler `new[]` producer, cookie/callback semantics, consumers, `delete[]` lifetime with the explicit post-delete pointer clear, source order, descriptive-name boundaries, and compiler/runtime no-standalone-emission disposition. Emitter position `20` places this declaration after complete `PatchFileSlice` at position `10`.
