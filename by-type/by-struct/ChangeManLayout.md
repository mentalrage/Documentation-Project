*** UID:0001TW | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:00001K | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ChangeMan Layout

## Status

- Confidence: strong for field offsets and allocation size.
- Owner class: [UID:00001K][ChangeMan](by-class/ChangeMan.md).
- Parent attachment: attached to [UID:00001K][ChangeMan](by-class/ChangeMan.md), which is scored `84/88`; this layout is now above the `80/80` child attachment gate.
- Evidence: IDA constructor/destructor decompilation, `Application::Initialize` allocation site, and `g_pChangeMan` xrefs.
- Reconstructable: yes, as source-level class layout information. Do not emit final C++ until the `SortedList` declaration and `ChangeMan` listener interface names are proven.

## Layout

```text
0x00  LObject/vtable
0x04  SortedList* changeList
0x08  end of object / sizeof(ChangeMan)
```

`Application::Initialize` allocates `0x08` bytes and calls `ChangeMan::ChangeMan` at `0x004644c1`. The constructor calls `LObject` setup, publishes `this` through [UID:0000QI][g_pChangeMan](by-global/g_pChangeMan.md), installs the [UID:0001X7][ChangeManVtable](by-type/by-vtable/ChangeManVtable.md), allocates a 24-byte [UID:0000DF][SortedList](by-class/SortedList.md), and stores the returned list pointer at `+0x04`.

## Registration Storage

The list is constructed as `SortedList(0x10, CompareChangeEntries, 100)`. Each row is a 16-byte [UID:0001TV][ChangeManEntry](by-type/by-struct/ChangeManEntry.md):

```text
0x00  owner
0x04  listener
0x08  scope
0x0c  messageType
```

The comparator at `0x0047ef20` sorts only by the `owner` field. Register/unregister/dispatch methods use the list through virtual container calls rather than embedding list storage in the `ChangeMan` object itself.

## Teardown

The scalar deleting destructor at `0x0047ef50` writes the `ChangeMan` vtable, destroys `changeList` through its virtual destructor with delete flag `1`, clears the `+0x04` field, clears [UID:0000QI][g_pChangeMan](by-global/g_pChangeMan.md), chains to `LObject` cleanup, and optionally frees the object.

The constructor cleanup fragment at `0x0047ed20-0x0047ed50` performs the same partial-list cleanup and singleton clear during exception unwind. It is compiler-generated cleanup, not handwritten source behavior.

## IDA MCP Evidence

- 2026-05-31 decompilation of `0x0047ec70` confirms constructor setup: `LObject` initialization, [UID:0000QI][g_pChangeMan](by-global/g_pChangeMan.md) / `dword_67AB2C` publication, `ChangeMan` vtable install, 24-byte `SortedList` allocation, and `SortedList(16, sub_47EF20, 100)` stored at `this + 4`.
- 2026-05-31 decompilation of `0x0047ef50` confirms the scalar deleting destructor reads `Block[1]`, installs the `ChangeMan` vtable, calls the list virtual destructor with delete flag `1`, clears `Block[1]`, clears `dword_67AB2C`, calls `LObject` cleanup, and optionally frees the object.
- 2026-05-31 decompilation of `0x0047ed50` and `0x0047ee20` confirms all registration/dispatch methods use `this[1]` as the external sorted-list pointer rather than embedded list storage.

## Score Rationale

The layout is scored in the low 80s because the complete object size, vtable base, singleton publication, `+0x04` list pointer, constructor allocation, destructor cleanup, comparator-driven record storage, and registration/dispatch usage are all documented and cross-linked. Confidence is slightly higher than completion because the remaining gaps are source-facing names and interface ownership rather than field offsets or object size.

## Open Questions

- Final source should decide whether the global singleton pointer is exposed directly or hidden behind a manager accessor/template wrapper.
- The list comparator and record layout are strong, but final listener/message type names still need a separate interface pass.

## Cross-References

- [UID:0000I2][ChangeMan](by-file/ChangeMan.md)
- [UID:00001K][ChangeMan](by-class/ChangeMan.md)
- [UID:0000ZU][0x0047ec70-0x0047efae.ChangeMan](by-memory/0x0047ec70-0x0047efae.ChangeMan.md)
- [UID:0001X7][ChangeManVtable](by-type/by-vtable/ChangeManVtable.md)
- [UID:0001TV][ChangeManEntry](by-type/by-struct/ChangeManEntry.md)
- [UID:0000QI][g_pChangeMan](by-global/g_pChangeMan.md)
- [UID:0001P4][0x0067ab2c-0x0067ab30.g_pChangeMan](by-memory/0x0067ab2c-0x0067ab30.g_pChangeMan.md)
- [UID:0000DF][SortedList](by-class/SortedList.md)

## Changes

- What existed before: the layout table described `0x08` as `end / allocated size`, and the page was scored unevaluated.
- What changed: `0x08` is now explicitly described as the end of the 8-byte object, the page is marked reconstructable, and the evidence section records live IDA MCP constructor/destructor checks.
- Summary/evidence: IDA MCP rechecked constructor `0x0047ec70`, registration/dispatch helpers `0x0047ed50` and `0x0047ee20`, comparator `0x0047ef20`, and scalar deleting destructor `0x0047ef50`.

- 2026-06-06: Completion/confidence changed from `78/89` to `82/90`, and `AUTOGEN_PARENT_UID` was set to [UID:00001K][ChangeMan](by-class/ChangeMan.md).
  - Before: the page had enough constructor/destructor/list evidence for attachment, but the metadata stayed below the parent-child gate and the manual by-struct coverage row still described an old `50%` state.
  - After: the page records the attachment gate, score rationale, and coverage report sync.
  - Evidence: existing documented IDA MCP checks cover the 8-byte allocation, `this + 4` `SortedList*`, singleton publication/clear, destructor list release, and registration/dispatch calls through the external list pointer.
