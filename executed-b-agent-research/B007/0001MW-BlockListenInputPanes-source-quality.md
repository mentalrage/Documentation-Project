** TARGET-REPORT-UID:0001MW **
** AUTHOR-AGENT-ID:B007 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B007 Report: [UID:0001MW] BlockListenInputPanes Source-Quality

## Assignment

- Agent: B007
- Assignment id: `B007-report-0001MW-block-listen-input-panes-source-quality-20260626`
- Mode: report-only research.
- Target: [UID:0001MW] `by-memory/0x005b68c0-0x005b7354.BlockListenInputPanes.md`
- Required report path: `tools/leaser/Agents/Agent-B007/research/0001MW-BlockListenInputPanes-source-quality.md`
- Report-only compliance: no by-* documentation, generated/project-level files, manual coverage files, validator/tool state, or IDA DB files were edited. No leases were acquired.
- MCP compliance: live IDA MCP was available and used; this is not a fallback-only report.

## Executive Recommendation

Implement after supervisor validation.

[UID:0001MW] should stop being a reconstructable emitter target. It is a reviewed source-island inventory for `BlockListenInputPanes.cpp`, not one source-authored function or class body.

Recommended target metadata:

```text
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000HS | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Keep the formal `RECONSTRUCTION_CPP CODE` block blank. Add target-specific no-code proof: the range contains multiple exact child functions/constructors, retained raw packet helpers, command-dispatcher switch-table bytes, and padding. Any parent C++ would either duplicate child C++ or emit compiler data and alignment bytes as if they were source code.

The correct disposition is a non-emitting split index under [UID:0000HS] `NexusTK/social/BlockListenInputPanes.cpp`. The exact children already carry, or should carry, all source C++ and no-code proofs.

## Current Target State

The current target page has:

| Field | Current | Recommended |
| --- | --- | --- |
| `COMPLETION` | `85` | `90` |
| `CONFIDENCE` | `88` | `92` |
| `CANONICAL_OWNER` | `0000HS` | `0000HS` |
| `RECONSTRUCTABLE` | `TRUE` | `FALSE` |
| `EMITTER_UIDS` | `0000HS` | blank |
| formal C++ | blank | blank |

The current prose already recognizes that [UID:0001MW] is an aggregate map covering constructors, handlers, switch-table bytes, raw packet helpers, padding, config-vector behavior, and source-file attachment. The metadata still treats it as reconstructable/emitting, which contradicts the exact-child split policy and leaves the blank C++ block looking like an unresolved source-quality problem.

The implementation repair should make the page an explicit non-emitting split index, not a source-body target.

## Evidence Basis

Current documentation and reports checked as direct evidence or leads:

- [UID:0001MW] `by-memory/0x005b68c0-0x005b7354.BlockListenInputPanes.md`
- [UID:0000HS] `by-file/BlockListenInputPanes.md`
- [UID:00000X] `by-class/BlockListenInputPane.md`
- [UID:00000A] `by-class/AddToBlockListenInputPane.md`
- [UID:00003N] `by-class/DeleteFromBlockListenInputPane.md`
- [UID:0001MV] `BlockListenInputPaneConstructor`
- [UID:0001MX] `BlockListenInputPaneKeyHandler`
- [UID:0001MY] `BlockListenInputPaneCommandDispatcher`
- [UID:0002RY] `SendBlockListenModePacket`
- [UID:0001MZ] `AddToBlockListenInputPaneConstructor`
- [UID:0001N0] `AddToBlockListenInputPaneSubmit`
- [UID:0002S0] `SendAddBlockListenPacket`
- [UID:0001N1] `DeleteFromBlockListenInputPaneConstructor`
- [UID:0001N2] `DeleteFromBlockListenInputPaneConfirm`
- [UID:0002RZ] `SendDeleteBlockListenPacket`
- [UID:0001N3] `FindBlockListEntry`
- [UID:0000Q5] `by-global/g_packetSender.md`
- [UID:0000Q5 memory/global support] `by-memory/0x0067a7ec-0x0067a7f0.g_packetSender.md`
- [UID:0001PU] `by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md`
- [UID:0003JY] `by-type/by-struct/SimpleUStringVectorLayout.md`
- `by-memory/0x00575380-0x00575470.PacketBufferScalarBigEndianWriteHelpers.md`
- `by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md`
- `by-type/by-vtable/CommandInputPaneVtableFamily.md`
- `by-type/by-vtable/BlockListenInputPaneFamilyVtables.md`
- `by-project-structure/proposed-source-tree.md`
- Executed B-agent reports for [UID:0001MV], [UID:0002RY], [UID:0002S0], [UID:0002RZ], and [UID:0001N3]

Generated tracker/coverage state was not edited and should not drive source edits when it conflicts with current source pages.

## Live IDA MCP Session

MCP was available and current. I did not use fallback-only evidence.

- Endpoint: `http://127.0.0.1:13337/mcp`
- Active session id: `80de0a67`
- IDB path: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`
- Input path: `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`
- Backend worker PID: `26892`
- Module: `NexusTK.exe`
- Imagebase: `0x400000`
- Health: `status: ok`, `auto_analysis_ready: true`, `hexrays_ready: true`, `strings_cache_ready: true`
- Active IDB state: `is_analyzing:false`

No IDA DB writes, renames, type changes, comments, or MCP management actions were performed.

## Live Boundary And Function Map

Live `lookup_funcs` on the target and nearby support range confirms this is not one IDA function:

| Address | Current IDA result |
| --- | --- |
| `0x005b68c0` | not a function |
| `0x005b6900` | `sub_5B6900`, size `0x11b` |
| `0x005b6a20` | `sub_5B6A20`, size `0x1df` |
| `0x005b6bff` | not a function |
| `0x005b6c00` | not a function |
| `0x005b6c30` | not a function |
| `0x005b6c7c` | not a function |
| `0x005b6c80` | not a function |
| `0x005b6cc0` | `sub_5B6CC0`, size `0x34e` |
| `0x005b700e` | not a function |
| `0x005b7010` | not a function |
| `0x005b70f7` | not a function |
| `0x005b7100` | not a function |
| `0x005b7140` | `sub_5B7140`, size `0x214` |
| `0x005b7354` | not a function |
| `0x005b7360` | not a function |
| `0x005b7450` | `sub_5B7450`, size `0x8d` |
| `0x005b74e0` | `sub_5B74E0`, size `0x73` |

The modeled functions inside [UID:0001MW] are only the key handler, command dispatcher, add submit handler, and delete confirm handler. The constructors and packet helpers in this source island are retained raw bodies or data/padding regions.

## Live Xref And Pointer Evidence

Live `xrefs_to` confirms a mixed vtable/data/call landscape rather than one callable source item:

| Target | Xref result |
| --- | --- |
| `0x005b68c0` | zero refs |
| `0x005b6900` | data refs at `0x0040ade3`, `0x0040b313`, `0x006306a4` |
| `0x005b6a20` | data ref at `0x00630694` |
| `0x005b6c30` | zero refs |
| `0x005b6c80` | zero refs |
| `0x005b6cc0` | data ref at `0x00630720` |
| `0x005b7010` | zero refs |
| `0x005b7100` | zero refs |
| `0x005b7140` | data ref at `0x006307ac` |
| `0x005b7360` | zero refs |
| `0x005b74e0` | code refs at `0x005b6d89` and `0x005b720d` |

Live raw pointer scan results align with that split:

- No raw VA pointer matches for retained constructor/helper starts `0x005b68c0`, `0x005b6c80`, `0x005b7100`, `0x005b6c30`, `0x005b7010`, or `0x005b7360`.
- Positive modeled-handler pointer matches:
  - `0x005b6900`: `0x0040ade7`, `0x0040b317`, `0x006306a4`
  - `0x005b6a20`: `0x00630694`
  - `0x005b6cc0`: `0x00630720`
  - `0x005b7140`: `0x006307ac`
- `0x005b74e0` has code call xrefs from add/delete handlers but no raw VA pointer match, which supports a private file-local helper route rather than a vtable entry.

The raw no-xref condition is a child-level liveness/confidence issue. It is not a reason for the parent aggregate to remain an emitter.

## Vtable Evidence

Live vtable refs identify the three source classes and their secondary/tertiary views:

| Vtable address | Current refs |
| --- | --- |
| `0x0063064c` | `0x005a72af`, `0x005aa336`, `0x005b68df` |
| `0x0063069c` | `0x005a72b7`, `0x005aa33c`, `0x005b68e7` |
| `0x006306cc` | `0x005a72c1`, `0x005aa346`, `0x005b68f1` |
| `0x006306d8` | `0x005b6b0a`, `0x005b6c9f` |
| `0x00630728` | `0x005b6b10`, `0x005b6ca7` |
| `0x00630758` | `0x005b6b1a`, `0x005b6cb1` |
| `0x00630764` | `0x005b6bd5`, `0x005b711f` |
| `0x006307b4` | `0x005b6bdb`, `0x005b7127` |
| `0x006307e4` | `0x005b6be5`, `0x005b7131` |

These refs support class-specific child pages:

- [UID:0001MV], [UID:0001MX], and [UID:0001MY] belong to [UID:00000X] `BlockListenInputPane`.
- [UID:0001MZ] and [UID:0001N0] belong to [UID:00000A] `AddToBlockListenInputPane`.
- [UID:0001N1] and [UID:0001N2] belong to [UID:00003N] `DeleteFromBlockListenInputPane`.

The vtables do not justify one broad parent source body.

## Byte And Body Evidence

Current byte reads confirm the important non-source regions:

- `0x005b6c00-0x005b6c30` begins `82 6a 5b 00 34 6b 5b 00 ef 6b 5b 00 ...`; this is a dispatcher switch/jump table for [UID:0001MY], not a standalone function.
- `0x005b6c30-0x005b6c7c` is a 76-byte raw helper body beginning `55 8b ec 83 ec 14 ...` and ending with `5d c3`.
- `0x005b7010` begins a raw packet helper body with `55 8b ec 81 ec 04 05 00 00 ...`.
- `0x005b7100-0x005b7140` is a raw constructor body beginning `55 8b ec 51 56 8b f1 ... 6a 29 ...` and ending with `5d c3`.
- `0x005b7354-0x005b7360` is twelve `0xcc` bytes after [UID:0001N2].
- `0x005b7360` begins the adjacent delete-packet helper outside the target range.
- `0x005b7447-0x005b7450` is nine `0xcc` bytes after [UID:0002RZ].
- `0x005b74e0` begins [UID:0001N3] `FindBlockListEntry`.

The target page should also add a missing split-index padding row for `0x005b700e-0x005b7010`: two `0xcc` bytes between [UID:0001N0] and [UID:0002S0]. That row is already supported by the exact child boundary evidence and prevents the parent inventory from looking like a direct fall-through from add submit into the retained add packet helper.

## Callee And Decompiler Evidence

Live `callees` and decompiler checks confirm child-level source shapes:

- `0x005b6900` calls narrow/event/string helpers, `Alert`, and the base `CharInputPane` key handler. It implements the block-list display key path.
- `0x005b6a20` calls character input helpers, allocation/alert helpers, `LanguageMan::GetLocalizedString`, and `LineInputPane` construction. It implements the A/a and D/d command dispatcher.
- `0x005b6cc0` calls input/string helpers, [UID:0001N3] `FindBlockListEntry`, `_wcscpy_s`, `__wcsupr_s`, allocation/alert helpers, config persistence, `PacketBufferWriteUInt8`, `WideCharToMultiByte`, `memmove`, `QueueAndSendPacket`, and security/rangecheck helpers. It implements add submit and inline add-packet send behavior.
- `0x005b7140` calls input/string helpers, [UID:0001N3] `FindBlockListEntry`, string/vector erase support, config persistence, `PacketBufferWriteUInt8`, `WideCharToMultiByte`, `memmove`, `QueueAndSendPacket`, and security/rangecheck helpers. It implements delete confirm and inline delete-packet send behavior.
- `0x005b74e0` calls string data/compare/release helpers and implements the private case-insensitive find helper.

Wrapper/helper decompiles used as support:

- `0x00575380` decompiles as `char __cdecl sub_575380(char a1, _BYTE *a2) { *a2 = a1; a2[1] = 0; return a1; }`, supporting source-facing `PacketBufferWriteUInt8(value, destination)` and the local spare-zero convention.
- `0x00516220` decompiles as `void *__stdcall sub_516220(void *a1, void *Src, size_t Size) { return memmove(a1, Src, Size); }`.
- `0x00574bb0` allocates/copies a queued packet and dispatches command `8` through the socket layer, supporting `QueueAndSendPacket(g_packetSender, packet, length)`.
- `0x00516030` currently decompiles as `int sub_516030() { return unk_69B4FC; }` in this IDA session; for this target it is only a low-level helper seen in queue/send support, not a BlockListen ownership signal.
- `0x00582950` is the wide case-insensitive compare wrapper.
- `0x00584540` returns the string data pointer used by `SimpleUString`/string helpers.

## Packet Helper Instruction Evidence

Focused instruction checks confirm the packet shapes and subcommands:

Mode packet helper [UID:0002RY] at `0x005b6c30-0x005b6c7c`:

- `0x005b6c44`: push opcode `0x0d`
- `0x005b6c46`: call `PacketBufferWriteUInt8`
- `0x005b6c4f`: push subcommand `1`
- `0x005b6c51`: call `PacketBufferWriteUInt8`
- `0x005b6c56`: load `g_packetSender`
- `0x005b6c62`: write local spare zero
- `0x005b6c66`: push length `2`
- `0x005b6c69`: call `QueueAndSendPacket`

Add packet helper [UID:0002S0] at `0x005b7010`:

- pushes opcode `0x0d`
- pushes subcommand `2`
- converts the wide name through `WideCharToMultiByte`
- writes the low-byte wide length
- copies the converted bytes through the memmove wrapper
- sends length `convertedLength + 3`

Adjacent delete packet helper [UID:0002RZ] at `0x005b7360`:

- pushes opcode `0x0d`
- pushes subcommand `3`
- converts the wide name through `WideCharToMultiByte`
- writes the low-byte wide length
- copies converted bytes
- rangechecks length against `0x400`
- sends length `convertedLength + 3`

These helper bodies belong to exact child/helper pages. The parent aggregate should only inventory them.

## Child Ownership And C++ Disposition

| UID | Range | Recommended child disposition |
| --- | --- | --- |
| `0001MV` | `0x005b68c0-0x005b6900` | Keep [UID:00000X] owner/emitter, reconstructable true, formal constructor C++ present. Parent should not duplicate it. |
| `0001MX` | `0x005b6900-0x005b6a1b` | Keep [UID:00000X] owner/emitter, reconstructable true, blank C++ until a method-specific source-quality pass resolves event/string/config names. |
| `0001MY` | `0x005b6a20-0x005b6bff` | Keep [UID:00000X] owner/emitter, reconstructable true, blank C++ until a method-specific source-quality pass resolves dispatcher/control names. |
| none | `0x005b6c00-0x005b6c30` | Switch/jump table bytes for [UID:0001MY]. No standalone source child required and no C++. Keep as documented inventory/ignored compiler data. |
| `0002RY` | `0x005b6c30-0x005b6c7c` | Keep [UID:0000HS] owner/emitter, reconstructable true, blank C++ with exact no-route/no-function proof for the retained raw mode-packet helper. |
| none | `0x005b6c7c-0x005b6c80` | Padding, no C++. |
| `0001MZ` | `0x005b6c80-0x005b6cc0` | Keep [UID:00000A] owner/emitter, reconstructable true, formal constructor C++ present. Parent should not duplicate it. |
| `0001N0` | `0x005b6cc0-0x005b700e` | Keep [UID:00000A] owner/emitter, reconstructable true, blank C++ until a method-specific source-quality pass resolves add-submit naming/control flow. |
| none | `0x005b700e-0x005b7010` | Add missing split-index row as two bytes of padding. No C++. |
| `0002S0` | `0x005b7010-0x005b70f7` | Keep [UID:0000HS] owner/emitter, reconstructable true, formal `SendAddBlockListenPacket` C++ present. Parent should not duplicate it. |
| none | `0x005b70f7-0x005b7100` | Padding, no C++. |
| `0001N1` | `0x005b7100-0x005b7140` | Keep [UID:00003N] owner/emitter, reconstructable true, formal constructor C++ present. Parent should not duplicate it. |
| `0001N2` | `0x005b7140-0x005b7354` | Keep [UID:00003N] owner/emitter, reconstructable true, blank C++ until a method-specific source-quality pass resolves delete-confirm naming/control flow. |

Related outside-range helpers:

- [UID:0002RZ] `0x005b7360-0x005b7447` remains an adjacent file-local delete-packet helper with formal C++ and should not be absorbed into [UID:0001MW].
- [UID:0001N3] `0x005b74e0-0x005b7553` remains the separate file-local case-insensitive block-list find helper with formal C++ and two live code callers from add/delete handlers.

## Source-Form Decision

Accepted parent source form:

```text
Reviewed non-emitting split index for the BlockListenInputPanes.cpp source island.
```

Rejected parent source forms:

- A monolithic `BlockListenInputPanes()` function: no such function exists in IDA or the source model.
- A broad module-level C++ block containing all child method/helper bodies: would duplicate exact child emitters and include compiler data/padding.
- A file-local static helper for the whole range: contradicted by class vtables, method slots, and multiple source classes.
- A generated switch-table or vtable artifact only: contradicted by the source-authored child handlers and constructors.

The formal parent C++ block should stay blank because the page is the index, not the source emitter.

## Source Placement

Keep [UID:0000HS] `NexusTK/social/BlockListenInputPanes.cpp` as the file/source-family route.

Positive placement evidence:

- The exact children form a cohesive block-listen UI feature cluster.
- Add/delete handlers manipulate the same config vector at `g_pConfig + 0x2918fc/+0x291900`.
- Packet sends use block-listen opcode `0x0d` with subcommands `1`, `2`, and `3`.
- [UID:0001N3] is a private file-local helper used only by add/delete handlers.
- The proposed source tree already places this cluster under `NexusTK/social/BlockListenInputPanes.cpp`.

Rejected placements:

- `CommandInputPanes.cpp`: command/input-pane framework supports the UI mechanics, but block-list state and packet semantics are social/block-listen feature code.
- `ProtocolSend` or socket packet files: packet helpers are consumers of packet writer/socket support, not owners of the UI/config feature.
- `PacketBuffer` or `Socket`: they own reusable send/write primitives only.
- `Config`: config storage is used by add/delete handlers but does not own the UI pane or packet-sending behavior.
- Individual caller/vtable construction contexts: they prove class identity, not a different source file.

## Config Vector And Global Evidence

The block-listen add/delete handlers use the `g_pConfig` singleton at offsets already documented by support pages:

- `g_pConfig + 0x2918fc`: vector begin/storage pointer.
- `g_pConfig + 0x291900`: vector end pointer.
- The vector element shape matches `SimpleUStringVectorLayout`: a 12-byte vector triplet with pointer-backed `SimpleUString` handles.

Best source-facing field name remains a reconstructed project name, not a recovered symbol. Use a conservative form such as `m_blockListenNames` or the existing support-doc wording `block-list vector` until a broader config field pass standardizes the exact member name.

Negative type/name evidence:

- IDA does not recover an original `Config::m_blockListenNames` or `Config::m_blockListNames` symbol.
- The decompiler names are still raw offsets off `dword_67A7C8`.
- Prompt ids and alert ids are numeric/resource ids in current evidence; do not invent unrecovered constant names in parent C++.

This unresolved field spelling caps exact child method C++ confidence, but it does not justify parent emission.

## Generated And Decompiler Name Resolution

Accepted source-facing names or roles:

- `BlockListenInputPane`
- `AddToBlockListenInputPane`
- `DeleteFromBlockListenInputPane`
- `SendBlockListenModePacket` for [UID:0002RY], with no formal C++ yet because of no-route proof.
- `SendAddBlockListenPacket` for [UID:0002S0].
- `SendDeleteBlockListenPacket` for [UID:0002RZ].
- `FindBlockListEntry` for [UID:0001N3].
- `PacketBufferWriteUInt8` for `0x00575380`.
- `QueueAndSendPacket` for `0x00574bb0`.
- `g_pConfig`, `g_packetSender`, and `SimpleUStringVector` support names as documented.

Rejected or non-source labels:

- `sub_5B6900`, `sub_5B6A20`, `sub_5B6CC0`, `sub_5B7140`, `sub_5B74E0`.
- `dword_67A7C8` and raw offset names as final source.
- `dword_67A7EC` as final source for the packet sender.
- `unk_69B4FC` as a BlockListen ownership or API signal.
- Decompiler false interpretations of data fragments as generated methods, including the already documented `0x00680067` and `0x00690052` fragments on the delete class support page.
- Any new original resource constant names for prompt ids `0x27`, `0x28`, `0x29`, or alert ids without external resource-symbol proof.

## Aggregate-Vs-Split Heuristic Reanalysis

Positive evidence for a non-emitting split index:

- The page range contains multiple exact child source items with different class owners.
- Several child pages already have accepted first-draft C++.
- Several child pages are intentionally blank pending method-specific source quality.
- Raw helpers and constructors are not IDA functions and have no raw-start xrefs, but their exact child pages preserve that liveness evidence.
- The command-dispatcher switch table and padding cannot be emitted as source.
- The parent range starts and ends on source-island boundaries, but the interior is not one source definition.
- A project precedent exists in non-emitting mixed inventory pages such as `CommandInputPaneVtableFamily`.

Negative evidence against leaving `RECONSTRUCTABLE:TRUE` on the parent:

- The parent has no single prototype, call ABI, vtable slot, or source-level symbol.
- No caller can call `0x005b68c0-0x005b7354` as a unit.
- Parent C++ would conflict with exact child C++ ownership and generated output responsibilities.
- Keeping `EMITTER_UIDS:0000HS` makes the blank C++ block look like missing source text rather than a deliberate no-code index.

Conclusion: the source-quality repair is metadata and prose conversion to a non-emitting split index, not parent C++ generation.

## Score Movement Rationale

Recommended score: `COMPLETION:90`, `CONFIDENCE:92`.

Why it should rise:

- Current MCP verifies the live function/non-function map, child boundaries, xrefs, vtable refs, raw pointer negatives, packet helper bytes, switch table bytes, and support helper behavior.
- Exact child ownership/emitter routes are resolved.
- The parent no-code disposition is now an explicit source-quality conclusion.
- Source-file placement is resolved through [UID:0000HS] `BlockListenInputPanes.cpp`.
- The missing `0x005b700e-0x005b7010` padding row can be added to make the parent inventory complete.

Why it should not rise higher:

- [UID:0001MX], [UID:0001MY], [UID:0001N0], and [UID:0001N2] still need method-specific source-quality passes before final C++.
- [UID:0002RY] remains a retained raw no-route helper with blank formal C++.
- Original config field names and resource constant names are not recovered.
- Packet helper names are source-facing reconstruction names, not recovered decorated symbols.
- The parent remains an index, so its score reflects documentation completeness, not final emitted code.

## Recommended Target Text Changes

If accepted, update [UID:0001MW] at report-level detail:

- Change metadata to `COMPLETION:90`, `CONFIDENCE:92`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, and keep owner `0000HS`.
- Update the item summary to call the page a reviewed non-emitting split index for the `BlockListenInputPanes.cpp` source island.
- Update status/reconstruction notes to say formal C++ is intentionally blank because exact children own source bodies/no-code proofs.
- Add current MCP session facts: session `80de0a67`, IDB path, input path, health status, imagebase, and no IDA writes.
- Add the live function map from this report.
- Add live xref/pointer-scan evidence for modeled handlers and raw no-route starts.
- Add live vtable-ref evidence connecting children to [UID:00000X], [UID:00000A], and [UID:00003N].
- Add byte evidence for the switch table, raw mode packet helper, add/delete packet helper starts, and padding.
- Add a split-index row for `0x005b700e-0x005b7010`: two bytes of padding between [UID:0001N0] and [UID:0002S0].
- Preserve child disposition details and do not move child C++ into the parent.
- Preserve rejected alternatives: not `CommandInputPanes.cpp`, not `ProtocolSend`, not `Socket`, not `PacketBuffer`, not `Config`, not one monolithic helper/function.
- Add a change log entry for B007 2026-06-26 source-quality reanalysis.

## Recommended Support Doc Changes

Apply only after supervisor validation and with leases for files edited immediately.

[UID:0000HS] `by-file/BlockListenInputPanes.md`:

- Required update.
- Add that [UID:0001MW] is now a non-emitting split index rather than an emitting module map.
- Preserve `NexusTK/social/BlockListenInputPanes.cpp` as the source route.
- Preserve the file's existing constructor/helper/method source inventory.
- No metadata change is required unless validator or supervisor asks for a small support-score sync.

[UID:00000X] `by-class/BlockListenInputPane.md`:

- No required edit if current page already has equal-or-greater detail.
- It already keeps [UID:0001MV] constructor C++, [UID:0001MX] blank pending method names, and [UID:0001MY] blank pending method names under the class owner.
- Record no-edit proof in the implementation checklist if untouched.

[UID:00000A] `by-class/AddToBlockListenInputPane.md`:

- No required edit if current page already has equal-or-greater detail.
- It already keeps [UID:0001MZ] constructor C++ and [UID:0001N0] blank pending add-submit source-quality names.
- Record no-edit proof in the implementation checklist if untouched.

[UID:00003N] `by-class/DeleteFromBlockListenInputPane.md`:

- No required edit if current page already has equal-or-greater detail.
- It already keeps [UID:0001N1] constructor C++, [UID:0001N2] blank pending delete-confirm source-quality names, and rejects false generated/data fragments.
- Record no-edit proof in the implementation checklist if untouched.

Packet/config/vtable/helper support docs:

- `by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md`: no required edit; current page already documents the relevant config/vector offsets.
- `by-type/by-struct/SimpleUStringVectorLayout.md`: no required edit; current page already documents the vector shape needed by add/delete handlers.
- `by-memory/0x00575380-0x00575470.PacketBufferScalarBigEndianWriteHelpers.md`: no required edit; current page already supports `PacketBufferWriteUInt8` and the destination/value ABI convention.
- `by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md`: no required edit; current page already supports the socket queue/send helper role.
- `by-global/g_packetSender.md` and `by-memory/0x0067a7ec-0x0067a7f0.g_packetSender.md`: no required edit; current pages already classify packet sender ownership outside BlockListen.
- `by-type/by-vtable/CommandInputPaneVtableFamily.md`: no required edit; use as precedent only.
- `by-type/by-vtable/BlockListenInputPaneFamilyVtables.md`: no required edit unless implementation wants an optional note that [UID:0001MW] is now the non-emitting source-island index.

No manual edit is recommended for any generated tracker, validator state, project-level file, IDA DB file, or `-coverage-report.md`.

## Open Questions And Resolutions

Question: Should the parent remain `RECONSTRUCTABLE:TRUE` because the source file is reconstructable?

Resolution: no. The source file and child items are reconstructable, but this by-memory range is not one source definition. The parent should be a non-emitting index.

Question: Should a new child be created for the switch table at `0x005b6c00-0x005b6c30`?

Resolution: no new source child is required. It is compiler switch-table data for [UID:0001MY] and should remain documented as table bytes/no-code inventory.

Question: Should a new child be created for `0x005b700e-0x005b7010`?

Resolution: no standalone child is needed. Add a padding row to the parent inventory so the split map is complete.

Question: Should [UID:0002RY] gain first-draft C++ because [UID:0002S0]/[UID:0002RZ] have first-draft packet helper C++?

Resolution: not in this parent report. Current support for [UID:0002RY] preserves a stronger no-route/no-function blank-C++ proof. The exact helper page is the place for any later source-form challenge.

Question: Should [UID:0001N0] or [UID:0001N2] receive C++ in this implementation?

Resolution: not through [UID:0001MW]. They are exact source-bearing method children and need method-specific source-quality callbacks before formal C++ insertion.

## Implementation Callback Results

Implementation callback completed on 2026-06-26.

Changed by-* docs:

- `by-memory/0x005b68c0-0x005b7354.BlockListenInputPanes.md`
- `by-file/BlockListenInputPanes.md`

Report file updated with proof:

- `tools/leaser/Agents/Agent-B007/research/0001MW-BlockListenInputPanes-source-quality.md`

Leases:

- Acquired leases as `B007` for `by-memory/0x005b68c0-0x005b7354.BlockListenInputPanes.md` and `by-file/BlockListenInputPanes.md` immediately before editing.
- Released both leases immediately after the edit/validator batch. `current_leases.md` has no active `B007` lease rows after release.

Validator results from `E:\NTK\GhidraBridge\source-3\project-documentation`:

> Executable block R001 was removed from this report and preserved verbatim in [0001MW-BlockListenInputPanes-source-quality-removed.md](0001MW-BlockListenInputPanes-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

- Exit code: `0`
- `command_id`: `000000003045`
- `command_timestamp`: `2026-06-26T17:13:48-04:00`
- `ok`: `1`
- Relevant updates: `completion_update 90`, `confidence_update 92`, `canonical_owner_update 0000HS`, `autogen_registry_update ... true -> false`, `insert_header_blank`, reference-index additions for existing links.
- Side effects: validator-owned `tools/validator.ini` registry/reference updates and `project-level/-auto-completion-stats.md` projected-stats update were reported by the validator. These were tool-driven validator side effects, not manual edits.
- Generated refresh: `deferred`, `generated_refresh_command_id:000000003045`, `generated_refresh_timestamp:2026-06-26T17:13:48-04:00`.

> Executable block R002 was removed from this report and preserved verbatim in [0001MW-BlockListenInputPanes-source-quality-removed.md](0001MW-BlockListenInputPanes-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

- Exit code: `0`
- `command_id`: `000000003047`
- `command_timestamp`: `2026-06-26T17:13:55-04:00`
- `ok`: `1`
- Relevant updates: validator inserted the missing UID link for `0001MW`.
- Warnings: `missing_ref_uid` for `0003HN` and `0003YJ`; no manual registry repair was attempted.
- Side effects: validator-owned `project-level/-auto-completion-stats.md` projected-stats update was reported by the validator.
- Generated refresh: `deferred`, `generated_refresh_command_id:000000003047`, `generated_refresh_timestamp:2026-06-26T17:13:55-04:00`.

Post-validation queue check:

> Executable block R003 was removed from this report and preserved verbatim in [0001MW-BlockListenInputPanes-source-quality-removed.md](0001MW-BlockListenInputPanes-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

- Exit code: `0`
- `command_id`: `000000003052`
- `command_timestamp`: `2026-06-26T17:16:21-04:00`
- Worker running: `True`
- Queued jobs: `0`
- Processing jobs: `0`
- Queued generated refresh jobs: `0`
- Processing generated refresh jobs: `0`

No manual edits were made to generated files, project-level files, validator/tool state, IDA DB files, manual coverage files, or any `-coverage-report.md`.

## Implementation Callback Checklist

- [x] Acquire leases only for files that will be edited immediately.
  - Proof: leased only the two by-* files changed in this callback, then edited and validated them in the same batch.
- [x] Edit `by-memory/0x005b68c0-0x005b7354.BlockListenInputPanes.md`:
  - [x] Change `COMPLETION` from `85` to `90`.
    - Proof: header now has `*** COMPLETION:90 ... ***`; validator `000000003045` reported `completion_update 90`.
  - [x] Change `CONFIDENCE` from `88` to `92`.
    - Proof: header now has `*** CONFIDENCE:92 ... ***`; validator `000000003045` reported `confidence_update 92`.
  - [x] Keep `CANONICAL_OWNER:0000HS`.
    - Proof: header preserved `0000HS`; validator `000000003045` reported `canonical_owner_update ... 0000HS`.
  - [x] Change `RECONSTRUCTABLE` from `TRUE` to `FALSE`.
    - Proof: header now has `*** RECONSTRUCTABLE:FALSE ... ***`; validator `000000003045` reported registry update `true -> false`.
  - [x] Clear `EMITTER_UIDS`.
    - Proof: header now has blank `*** EMITTER_UIDS: ... ***`.
  - [x] Keep `EMITTER_POSITION_OPTIONAL` blank.
    - Proof: header remains blank.
  - [x] Keep the formal `RECONSTRUCTION_CPP CODE` block blank.
    - Proof: BEGIN/END block has no C++ between markers.
  - [x] Update the item summary/status to say reviewed non-emitting split index for `BlockListenInputPanes.cpp`.
    - Proof: item summary and Status now state reviewed non-emitting split index and no parent source-body emission.
  - [x] Add current MCP session facts from this report.
    - Proof: section `2026-06-26 B007 Source-Quality Implementation` records session `80de0a67`, IDB/input paths, PID, imagebase, health, and no IDA writes.
  - [x] Add current function/non-function boundary map.
    - Proof: target page includes the live `lookup_funcs` map for `0x005b68c0` through nearby `0x005b74e0`.
  - [x] Add xref and raw pointer-scan positives/negatives.
    - Proof: target page includes xref/pointer-route table for modeled handler starts and raw no-route starts.
  - [x] Add vtable evidence for [UID:00000X], [UID:00000A], and [UID:00003N].
    - Proof: target page includes nine vtable base rows and store/ref roles for all three classes.
  - [x] Add byte evidence for the switch table, raw helper bodies, and padding.
    - Proof: target page records switch-table bytes, mode/add packet helper byte/body evidence, constructor bytes, `0x005b700e-0x005b7010`, and `0x005b7354-0x005b7360`.
  - [x] Add the missing `0x005b700e-0x005b7010` padding row.
    - Proof: Covered Ranges now has the two-byte padding row between [UID:0001N0] and [UID:0002S0].
  - [x] Add child ownership/emitter/C++ disposition table at target-page detail.
    - Proof: target page now lists child ownership and C++/no-code disposition for [UID:0001MV] through [UID:0001N2] plus related outside helpers.
  - [x] Add parent no-code proof and rejected alternatives.
    - Proof: target page states broad parent C++ is rejected and lists rejected monolithic, `CommandInputPanes.cpp`, protocol/socket/packet/config ownership alternatives.
  - [x] Add score rationale for `90/92`.
    - Proof: Score Rationale now explains the `90/92` move and remaining caps.
  - [x] Add a B007 2026-06-26 change-log entry.
    - Proof: Changes section has a B007 source-quality implementation entry.
- [x] Edit `by-file/BlockListenInputPanes.md`:
  - [x] Add or refresh the support note that [UID:0001MW] is a non-emitting split index, not an emitting source-body page.
    - Proof: Status has a source-island index bullet, Proposed Contents has a [UID:0001MW] row, Ownership Notes has a non-emitting source-island index paragraph, and Changes has a B007 entry.
  - [x] Preserve `NexusTK/social/BlockListenInputPanes.cpp` as the source route.
    - Proof: Proposed module folder and candidate file remain unchanged; new [UID:0001MW] prose preserves `NexusTK/social/BlockListenInputPanes.cpp`.
  - [x] Preserve existing child constructor/helper/method source inventory.
    - Proof: Existing Proposed Contents rows for [UID:00000X], [UID:00000A], [UID:00003N], [UID:0002RY], [UID:0002S0], [UID:0002RZ], and [UID:0001N3] are retained.
  - [x] Record score/no-score-change rationale.
    - Proof: B007 Changes entry says no file metadata change.
- [x] Check `by-class/BlockListenInputPane.md`:
  - [x] Already equal-or-greater detail; no edit.
    - Proof: page already names [UID:0001MW] as module index, routes exact children [UID:0001MV]/[UID:0001MX]/[UID:0001MY] through the class, records constructor C++ readiness, handler blanks pending method names, and keeps the broader aggregate/file parent distinction.
- [x] Check `by-class/AddToBlockListenInputPane.md`:
  - [x] Already equal-or-greater detail; no edit.
    - Proof: page already names [UID:0001MW] as module index, routes [UID:0001MZ]/[UID:0001N0] through the class, records constructor C++ readiness, submit-handler blank C++ pending source-quality, config/vector evidence, and [UID:0002S0] as a retained file-local helper.
- [x] Check `by-class/DeleteFromBlockListenInputPane.md`:
  - [x] Already equal-or-greater detail; no edit.
    - Proof: page already names [UID:0001MW] as module index, routes [UID:0001N1]/[UID:0001N2] through the class, records constructor C++ readiness, confirm-handler blank C++ pending source-quality, config/vector evidence, and rejects false generated/data-fragment methods.
- [x] Record no-edit proof for support docs that already have equal-or-greater detail:
  - [x] `by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md`
    - Proof: page already documents `+0x2918fc` as block-list vector/storage span and keeps config member names descriptive/inferred.
  - [x] `by-type/by-struct/SimpleUStringVectorLayout.md`
    - Proof: page already documents the vector triplet, begin/end/capacity fields, and 4-byte pointer-backed string-handle slots.
  - [x] `by-memory/0x00575380-0x00575470.PacketBufferScalarBigEndianWriteHelpers.md`
    - Proof: page already documents `PacketBufferWriteUInt8`, value-first raw ABI, local spare-zero semantics, and [UID:0002RY] as a BlockListen consumer.
  - [x] `by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md`
    - Proof: page already documents Socket-owned `QueueAndSendPacket`, packet-size/local terminator semantics, generic send funnel role, and [UID:0002RY] BlockListen consumer evidence.
  - [x] `by-global/g_packetSender.md`
    - Proof: page already documents `Socket *g_packetSender`, Socket lifetime ownership, rejected generated aliases, and [UID:0002RY] as a BlockListen feature-packet consumer without owner movement.
  - [x] `by-memory/0x0067a7ec-0x0067a7f0.g_packetSender.md`
    - Proof: page already documents the exact storage, Socket lifetime writes, `Socket *` source-facing type direction, broad feature reads, and sender ownership outside BlockListen.
  - [x] `by-type/by-vtable/CommandInputPaneVtableFamily.md`
    - Proof: page is already a non-emitting mixed-owner vtable inventory with [UID:0003HN] split out for BlockListen, which is the accepted precedent for [UID:0001MW]'s broad non-emitting disposition.
  - [x] `by-type/by-vtable/BlockListenInputPaneFamilyVtables.md`
    - Proof: page already records the source-local three-class vtable family, owner [UID:0000HS], exact vtable bases, store refs, and split from the broad non-emitting command vtable inventory.
- [x] Do not edit generated files, project-level files, validator/tool state, IDA DB files, manual coverage files, or any `-coverage-report.md`.
  - Proof: no manual edits were made to those files. Validators reported tool-owned updates to `tools/validator.ini` and `project-level/-auto-completion-stats.md`; those are validator side effects from scoped validation, not manual edits.
- [x] Run scoped validators for each edited by-* file only.
  - Proof: ran one scoped file validator for the target by-memory page and one for `by-file/BlockListenInputPanes.md`; both exited `0` with `ok:1`.
- [x] Release leases immediately after the corresponding file edits and validators.
  - Proof: `python leaser.py B007 unlease ...` succeeded for both leased files, and current lease report has no active `B007` rows.
- [x] Update this report checklist with proof during the implementation callback, including exact files touched, validator commands/results, no-edit proofs, generated-state observations, and lease release status.
  - Proof: this section records changed files, validator command IDs/timestamps/results, no-edit support proofs, deferred generated refresh state, and lease release status.

Unchecked blockers:

- None.

## Final Implementation Callback Status

Implementation is ready for supervisor verification. The accepted repair has been applied: [UID:0001MW] is now a `90/92` non-emitting split index under [UID:0000HS], the parent formal C++ block remains blank with explicit no-code proof, exact child source/no-code responsibilities are preserved, [UID:0000HS] records the source-island index role, support pages were checked with no-edit proof, validators passed, and leases were released.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B007","command_id":"000000004165","destination_path":"executed-b-agent-research/B007/0001MW-BlockListenInputPanes-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B007/research/0001MW-BlockListenInputPanes-source-quality.md","timestamp":"2026-06-26T17:19:06","uid":"0001MW"} -->
<!-- {"agent":"B007","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001MW-BlockListenInputPanes-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B007/0001MW-BlockListenInputPanes-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001MW"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
