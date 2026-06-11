*** UID:0000S8 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000NO | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pServerSelectPane

## Status

- Confidence: strong for address, lifetime role, and ServerSelectPane ownership; medium-high for final symbol spelling.
- Address: `0x0069b4ac`
- Alias candidates: `g_serverSelectPane`, `g_pServerSelectPane`, IDA `dword_69B4AC`
- Proposed owner file: [UID:0000NO][ServerSelectPane](by-file/ServerSelectPane.md)

## Symbol Role

`g_pServerSelectPane` tracks the active pre-login server-selection dialog. The constructor installs the active pane pointer, the non-deleting destructor helper and scalar deleting destructor clear it, and main-menu cleanup/startup code reads it while closing pre-login singleton panes.

Use `g_pServerSelectPane` as the preferred documentation name because the value is a process-wide pointer to the active pane. Keep `g_serverSelectPane` as an alias unless later source-level evidence proves the original spelling omitted the pointer prefix.

## IDA MCP Evidence

Checked on 2026-05-30 with live IDA MCP:

- `0x0069b4ac` is a 4-byte `.data` item named `dword_69B4AC`; IDA reports 7 data xrefs.
- Main-menu cleanup at `0x004f69a0` reads the pointer at `0x004f69fb`, tests it, and calls `0x0049dad0` when non-null. This is part of the same cleanup run that closes adjacent pre-login singleton panes.
- Main-menu startup / server-select creation path at `0x004f6d80` tests `dword_69B4AC` at `0x004f70a8`; when it is null, it allocates `0x270` bytes and proceeds toward ServerSelectPane construction.
- `0x00573d20` is the ServerSelectPane construction path. It stores the adjusted object pointer into `dword_69B4AC` at `0x00573d7e`, clears it on the null fallback at `0x00573d85`, and then installs `ServerSelectPane` vtables at `0x00573d8f`, `0x00573d98`, and `0x00573da2`.
- `0x00574310` is a non-deleting destructor-like helper. It restores ServerSelectPane vtables and clears `dword_69B4AC` at `0x0057432a`.
- `0x00574750` is a tiny cleanup helper that clears `dword_69B4AC` directly.
- `0x00574780` is the scalar deleting destructor path; it restores ServerSelectPane vtables and clears `dword_69B4AC` at `0x005747a0`.
- IDA MCP `py_eval` on 2026-06-07 reconfirmed the exact slot as `0x0069b4ac-0x0069b4b0`, bytes `ff ff ff ff`, initial dword `0xffffffff`, and the same seven direct xrefs. The exact storage subrange is now split as [UID:0002XN][0x0069b4ac-0x0069b4b0.g_pServerSelectPane](by-memory/0x0069b4ac-0x0069b4b0.g_pServerSelectPane.md).

## Ownership Notes

- Keep this global with `login/ServerSelectPane.cpp`, not with generic dialog or chat code.
- If later source-output views expose both `g_serverSelectPane` and `g_pServerSelectPane`, merge them to this canonical page before source migration.

## Cross-References

- [UID:0000NO][ServerSelectPane](by-file/ServerSelectPane.md)
- [UID:0000D2][ServerSelectPane](by-class/ServerSelectPane.md)
- [UID:0001HR][0x00573d20-0x005747df.ServerSelectPane](by-memory/0x00573d20-0x005747df.ServerSelectPane.md)
- [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md)

## Changes

- 2026-06-05: Marked reconstructable and attached to [UID:0000NO][ServerSelectPane](by-file/ServerSelectPane.md) to resolve the global unclassified coverage row.
  - Reasoning: live IDA xrefs bind the singleton to the pre-login server-selection constructor/destructor paths and main-menu cleanup/create guards, and the proposed source tree keeps this module under `login/ServerSelectPane.cpp`. No score change and no reconstruction C++ were added.
- What existed before: this page had correct older IDA notes but remained unevaluated for completion/confidence and still framed the alias decision around source-output reconciliation.
- What changed to: the page now records the current live IDA MCP xref set, constructor/destructor write sites, main-menu read sites, and a scoped alias decision. Completion/confidence were set to `82/88`.
- Summary and evidence: IDA MCP on 2026-05-30 verified `0x0069b4ac` / `dword_69B4AC` as a 4-byte `.data` global with 7 xrefs: main-menu cleanup read at `0x004f69fb`, startup/create guard at `0x004f70a8`, constructor assignment at `0x00573d7e`, constructor fallback clear at `0x00573d85`, destructor helper clear at `0x0057432a`, cleanup helper clear at `0x00574750`, and scalar deleting destructor clear at `0x005747a0`.
- 2026-06-07 Batch 043 split-parent refresh:
  - Before: `82/88`, below the corrected child-and-parent `85/85` completion gate for the exact storage split.
  - After: `86/88`.
  - Evidence: live IDA MCP reconfirmed the exact four-byte item, initial bytes/dword, and all seven lifecycle xrefs; the new exact memory page carries the storage-side row and this page remains the direct canonical global owner.
