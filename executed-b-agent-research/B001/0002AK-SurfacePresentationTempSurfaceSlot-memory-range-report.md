** TARGET-REPORT-UID:0002AK **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002AK SurfacePresentationTempSurfaceSlot Memory Range Advanced-Scan Report

## Finalized Report / Current Recommendation

- Current recommendation: repair the target page text and stale byte-evidence wording; do not change UID, range, owner, emitter, reconstruction state, or score.
- Final disposition: the advanced-scan finding is a real scanner-visible document-label gap. Current IDA MCP and PE/raw checks also contradict the older `all ff` / `0xffffffff` byte wording in the target and shared coverage text.
- Required action: add exact `SurfacePresentationTempSurfaceSlot` document text, correct initial-byte wording to zero-initialized `.data` virtual-tail storage, and update one historical `AUTOGEN_PARENT_UID` wording line to current owner/emitter terminology.
- Routing decision: keep `CANONICAL_OWNER:0000OC`, keep `EMITTER_UIDS:0000OC`, keep `RECONSTRUCTABLE:TRUE`, and keep final C++ blank under the active 90/90+ code-entry gate.
- Confidence: high for the label and byte-evidence repair; high for the current range and Surface routing; medium-high for the provisional source-level variable name/type.

## Supporting Research

## Target

- Target UID: `0002AK`
- Target path: `by-memory/0x0069ba3c-0x0069ba40.SurfacePresentationTempSurfaceSlot.md`
- Source queue/report row: `auto-generated/by-memory-tool-report.md` Advanced-Error-Scan
- Exact scanner complaint: `0x0069ba3c-0x0069ba40.SurfacePresentationTempSurfaceSlot.md: missing document text for SurfacePresentationTempSurfaceSlot`
- Current supervisor classification: `error-repair-assigned` to Agent-B001 in `tools/leaser/Agents/Supervisor_notes.md`
- Current header state:

```text
UID:0002AK
COMPLETION:85
CONFIDENCE:91
CANONICAL_OWNER:0000OC
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000OC
EMITTER_POSITION_OPTIONAL:
RECONSTRUCTION_CPP CODE: blank
```

Current generated routing:

```markdown
| [UID:0002AK][0x0069ba3c-0x0069ba40.SurfacePresentationTempSurfaceSlot](by-memory/0x0069ba3c-0x0069ba40.SurfacePresentationTempSurfaceSlot.md) | emits | `0000OC` | `0000OC` |  | no | `auto-generated/NexusTK/render/Surface.cpp` | `by-memory/0x0069ba3c-0x0069ba40.SurfacePresentationTempSurfaceSlot.md` |  |
```

## Executive Recommendation

The target should remain routed as-is:

- Keep `CANONICAL_OWNER:0000OC` / [UID:0000OC] `Surface`.
- Keep `EMITTER_UIDS:0000OC`.
- Keep `RECONSTRUCTABLE:TRUE`.
- Keep scores `85/91`.
- Keep final reconstruction C++ blank because the exact source variable name and DirectDraw wrapper/object type are still provisional.
- Do not apply an IDA rename. Current IDA renders the slot as `unk_69BA3C`; the compact filename label is useful documentation text, but not proven as an original source name.

The page does need a documentation repair. A text search over the target found no literal `SurfacePresentationTempSurfaceSlot` in the body or title, while the filename and generated reports use that compact label. The page and shared coverage row also say the slot is initialized to `ff ff ff ff` / `0xffffffff`; current IDA MCP and read-only PE mapping show `0x0069ba3c` is zero-initialized virtual `.data` tail storage.

## Supervisor Active Recheck

The supervisor assignment asked whether the memory-ranges advanced-scan warning is only a scanner-visible label/title mismatch or a real documentation/range/name/owner/emitter issue.

Result:

- Scanner label issue: yes, real. The target page lacks exact `SurfacePresentationTempSurfaceSlot` document text.
- Documentation evidence issue: yes, real. The current target page and `by-memory/-coverage-report.md` row contain stale `all ff` / `0xffffffff` byte wording for this slot.
- Range issue: no. `0x0069ba3c-0x0069ba40` remains a clean four-byte slot.
- Filename issue: no. The current filename is correct and already contains the generated label.
- Metadata issue: no. Current owner/emitter/routing is still supported.
- Split/merge issue: no. Adjacent slots have unrelated xref sets and different lifecycle/use patterns.
- IDA-safe name repair: no. `SurfacePresentationTempSurfaceSlot` is a provisional documentation label, not a proven IDA database name.

No by-* files or coverage report files were edited in this assignment, per user instruction.

## Evidence Standards Used

Evidence checked:

- Current B001 `goal.md`
- `by-structure.md`
- `inference_research.md`
- `by-project-structure/proposed-source-tree.md`
- Target page and directly related `Surface`, `SurfacePresentation`, `SurfaceMinimapRenderInitializer`, and `SurfaceRenderCallbackTable` docs
- Current generated memory coverage and memory tool reports
- Live IDA MCP `server_health`, `lookup_funcs`, `xrefs_to`, `get_bytes`, `get_global_value`, `insn_query`, and `entity_query`
- Read-only raw PE section mapping for `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- Lease state checks

The evidence is strong enough to recommend target text repair and stale byte wording correction. It is not strong enough to enter final C++ or apply a recovered source variable name.

## IDA MCP Facts

Session:

- IDA MCP session: `b001_0003gy`
- Input binary: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- IDB: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`
- Image base: `0x00400000`
- Auto-analysis ready: `true`
- Hex-Rays ready: `true`

Function/range facts:

| Address | Function |
| --- | --- |
| `0x00558840` | `sub_558840`, size `0x723` |
| `0x00558a53` | inside `sub_558840`, size `0x723` |
| `0x00558a90` | inside `sub_558840`, size `0x723` |
| `0x00558aa5` | inside `sub_558840`, size `0x723` |
| `0x00558ae6` | inside `sub_558840`, size `0x723` |
| `0x00558f63` | no modeled function start; end boundary of `sub_558840` |

Xref facts:

| Address | Direct xref count | Meaning |
| --- | ---: | --- |
| `0x0069ba30` | 0 | Previous unreferenced dword; separate. |
| `0x0069ba34` | 5 | Unrelated previous slot used by `sub_549C20`, `sub_54A480`, `sub_54A4B0`, `sub_54B000`, and `sub_54B520`. |
| `0x0069ba38` | 8 | Previous VoteMenuPane singleton pointer; separate owner. |
| `0x0069ba3c` | 4 | This target temporary surface slot. |
| `0x0069ba40` | 6 | Following packet-transform mutable state; separate owner/use path. |

Current direct xrefs to `0x0069ba3c`:

```text
0x00558a53  sub_558840
0x00558a90  sub_558840
0x00558aa5  sub_558840
0x00558ae6  sub_558840
```

Local instruction facts from `0x00558a40-0x00558af4`:

```text
0x00558a53  push offset unk_69BA3C
0x00558a5b  call dword ptr [eax+10h]
0x00558a90  mov eax, dword ptr unk_69BA3C
0x00558a95  mov ecx, dword ptr unk_67AB1C
0x00558a9d  call sub_4651D0
0x00558aa5  push dword ptr unk_69BA3C
0x00558aab  call dword ptr [esi+20h]
0x00558ae6  push dword ptr unk_69BA3C
0x00558aef  call dword ptr [ecx+70h]
```

Interpretation:

- `0x00558a53` passes the address of the slot as an out-parameter to a DirectDraw-style vtable call.
- `0x00558a90` reads the returned pointer from the slot.
- `0x00558aa5` passes the created pointer to another vtable call after obtaining an application-derived value through `sub_4651D0`.
- `0x00558ae6` passes the same stored pointer while configuring the presentation object's retained surface field through another vtable call.

Data/name facts:

- `get_bytes` returned zero bytes for `0x0069ba30-0x0069ba50`, including `0x0069ba3c-0x0069ba40`.
- `get_global_value` returned `0x0` for `0x0069ba30`, `0x0069ba34`, `0x0069ba38`, `0x0069ba3c`, and `0x0069ba40`.
- `entity_query` over `0x0069ba20-0x0069ba50` returned no named IDA globals or names. IDA renders this target as `unk_69BA3C`.

## PE / Raw Evidence

Read-only PE mapping of `NexusTK.exe`:

```text
ImageBase: 0x00400000
Target section: .data
  VA: 0x0066d000-0x0069ce24
  VirtualSize: 0x2fe24; RawSize: 0xd800; PointerToRawData: 0x26ac00
  Raw-backed VA end: 0x0067a800
  Target is in virtual zero-fill tail, not backed by initialized raw bytes.
```

Conclusion: current loader/IDA state for `0x0069ba3c-0x0069ba40` is zero-filled storage, not raw initialized `ff ff ff ff`. The old page wording is stale evidence. This does not invalidate the four-byte slot range or Surface ownership, but the target and shared coverage row should stop claiming all-`0xff` initialization.

## Current Documentation Facts

Target page:

- Header already has `CANONICAL_OWNER:0000OC`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000OC`.
- Title is currently `# Surface Presentation Temporary Surface Slot`, which lacks exact `SurfacePresentationTempSurfaceSlot`.
- Evidence currently says live IDA bytes are `ff ff ff ff` and that `dword_69BA3C` is initialized to `0xffffffff`.
- Assignment section routes the slot to [UID:0000OC] `Surface` because all refs are inside `0x00558840`.
- Historical change text still uses `AUTOGEN_PARENT_UID:0000OC`, which should be replaced with current owner/emitter wording when the page is repaired.

Related docs:

- [UID:00039W] `0x00558840-0x00558f63.SurfaceMinimapRenderInitializer` is `CANONICAL_OWNER:0000OC`, `EMITTER_UIDS:0000OC`, `86/88`; it documents `sub_558840` as DirectDraw/minimap/surface setup and lists `dword_69BA3C` among its data references.
- [UID:0000OC] `Surface` documents `Surface.cpp` as the provisional shared surface/presentation helper bucket, including `RenderMinimap` at `0x00558840-0x00558f63`.
- [UID:0001G6] `0x00557140-0x00559aef.SurfacePresentation` is a mixed non-emitting aggregate; exact children carry ownership. Its child inventory lists the `0x00558840-0x00558f63` initializer as Surface-owned.
- [UID:0000TN] `SurfaceRenderCallbackTable` also documents `0x00558840` as the surface initialization path that installs render callback/global state.
- `by-project-structure/proposed-source-tree.md` keeps `0x00557140-0x00559aef` under [UID:0000OC] `Surface` presentation review rather than migrating it to `MapPane.cpp`.

## Function / Child Inventory

| Item | Current state | Finding |
| --- | --- | --- |
| [UID:0002AK] `0x0069ba3c-0x0069ba40.SurfacePresentationTempSurfaceSlot` | `85/91`, owner/emitter `0000OC`, reconstructable data slot | Keep route; repair compact label text and stale byte wording. |
| [UID:00039W] `0x00558840-0x00558f63.SurfaceMinimapRenderInitializer` | `86/88`, owner/emitter `0000OC` | Direct code owner/use site for all four xrefs to this data slot. |
| [UID:0001G6] `0x00557140-0x00559aef.SurfacePresentation` | Mixed container, `RECONSTRUCTABLE:FALSE`, no single owner | Context only; not the canonical owner for this exact slot. |
| [UID:0001Q0] `0x0069ba38-0x0069ba3c.g_pVoteMenuPane` | Adjacent previous pointer slot | Rejected as merge candidate; separate refs and owner. |
| `0x0069ba40-...` packet-transform state | Adjacent following mutable state | Rejected as merge candidate; six separate refs in `sub_577030`. |

## Ownership / Emitter Analysis

Accepted owner/emitter:

- [UID:0000OC] `Surface`: accepted. Every direct xref to `0x0069ba3c` is inside `sub_558840`, and the current child/function docs classify that function as Surface/minimap DirectDraw presentation setup. The storage is a transient out-parameter/created-surface pointer used by that initializer path.

Rejected alternatives:

- `CANONICAL_OWNER:NONE`: rejected. This is not a pooled shared literal or ownerless data island. It has a single use route through the Surface initializer and an existing direct file owner.
- [UID:0001G6] `SurfacePresentation`: rejected as canonical owner. It is a mixed aggregate and explicitly relies on child pages for exact ownership.
- `VoteMenuPane` / `RightButtonMenuPane`: rejected. `0x0069ba38` is the vote popup singleton immediately before the target, but its eight xrefs are distinct and do not include this slot.
- `MapPane`: rejected as direct owner. The minimap result is map-related, but current docs and proposed source-tree notes treat `0x00558840` as shared Surface presentation setup, not MapPane source.
- `DirectX`: rejected. The function uses DirectDraw-style vtable calls, but DirectX is a dependency/provider, not the source owner of this temp storage slot.
- Packet transform state: rejected. `0x0069ba40` starts a separate following data item with six refs in `sub_577030`.

## Exact Required Edits

Do not edit `by-memory/-coverage-report.md` directly from this B-agent assignment. The following is the exact supervisor-applicable repair text.

### Target Page: `by-memory/0x0069ba3c-0x0069ba40.SurfacePresentationTempSurfaceSlot.md`

Replace the title:

```markdown
# Surface Presentation Temporary Surface Slot
```

with:

```markdown
# SurfacePresentationTempSurfaceSlot - Surface Presentation Temporary Surface Slot
```

Insert this summary bullet after the address range bullet:

```markdown
- Document label: `SurfacePresentationTempSurfaceSlot` is the current generated filename/report label for this temporary surface pointer slot; the exact original source variable name remains provisional.
```

Replace this evidence bullet:

```markdown
- Live IDA bytes for `0x0069ba3c-0x0069ba40` are `ff ff ff ff`, matching one pointer-sized storage slot initialized to the same sentinel pattern as nearby global slots.
```

with:

```markdown
- Current IDA MCP bytes for `0x0069ba3c-0x0069ba40` are `00 00 00 00`. A read-only PE/raw section check confirms `0x0069ba3c` lies in the zero-filled virtual tail of `.data` beyond the initialized raw-backed bytes, matching one pointer-sized storage slot default-initialized to null before the surface initializer writes it.
```

Replace this evidence bullet:

```markdown
- 2026-06-07 A001 IDA MCP reconfirmed the same boundaries: `dword_69BA3C` is a four-byte `.data` item initialized to `0xffffffff`; the only references are the four `0x00558840-0x00558f63` surface initializer sites listed above; `0x0069ba38` remains the VoteMenuPane singleton and `0x0069ba40` begins packet-transform mutable state.
```

with:

```markdown
- 2026-06-14 B001 IDA MCP recheck reconfirmed the same xref boundaries but corrected the initial-byte evidence: `unk_69BA3C` is a four-byte `.data` virtual-tail item currently read as `0x00000000`; the only references are the four `0x00558840-0x00558f63` surface initializer sites listed above; `0x0069ba38` remains the VoteMenuPane singleton and `0x0069ba40` begins packet-transform mutable state.
```

Replace this change-log line:

```markdown
  - Changed to: score `85/91`, `AUTOGEN_PARENT_UID:0000OC`.
```

with:

```markdown
  - Changed to: score `85/91`, `CANONICAL_OWNER:0000OC`, `EMITTER_UIDS:0000OC`.
```

Append this new change-log entry:

```markdown
- 2026-06-14 B001 memory-range advanced-scan audit recommendation:
  - Keep `CANONICAL_OWNER:0000OC`, `EMITTER_UIDS:0000OC`, `RECONSTRUCTABLE:TRUE`, score `85/91`, and blank C++.
  - Repair the scanner-visible compact label by adding exact `SurfacePresentationTempSurfaceSlot` document text.
  - Correct stale all-`ff` byte wording to current zero-initialized `.data` virtual-tail evidence; live IDA still confirms exactly four refs in `0x00558840-0x00558f63` and clean boundaries against the adjacent VoteMenuPane singleton and packet-transform state.
```

### Shared Coverage Report: `by-memory/-coverage-report.md`

Replace the current [UID:0002AK] row:

```markdown
    - [UID:0002AK][0x0069ba3c-0x0069ba40.SurfacePresentationTempSurfaceSlot](by-memory/0x0069ba3c-0x0069ba40.SurfacePresentationTempSurfaceSlot.md) 0x0069ba3c-0x0069ba40 | global-data pointer | SurfacePresentationTempSurfaceSlot : reconstructable : 85% : very-strong : Four-byte DirectDraw-style temporary surface slot assigned to `Surface`; live IDA confirms all-`0xff` bytes, exactly four refs in surface initializer `0x00558840-0x00558f63`, create/read/configure/attach use sites, and clean boundaries from neighboring VoteMenuPane and packet-transform storage.
```

with:

```markdown
    - [UID:0002AK][0x0069ba3c-0x0069ba40.SurfacePresentationTempSurfaceSlot](by-memory/0x0069ba3c-0x0069ba40.SurfacePresentationTempSurfaceSlot.md) 0x0069ba3c-0x0069ba40 | global-data pointer | SurfacePresentationTempSurfaceSlot : reconstructable : 85% : very-strong : Four-byte DirectDraw-style temporary surface slot assigned to `Surface`; current IDA MCP and PE/raw checks confirm zero-initialized `.data` virtual-tail storage at `0x0069ba3c`, exactly four refs in surface initializer `0x00558840-0x00558f63`, create/read/configure/attach use sites, and clean boundaries from neighboring VoteMenuPane and packet-transform storage.
```

### Generated Coverage Report

No replacement is needed for `auto-generated/-ag-memory-coverage.md`; the current row already has the correct owner/emitter route:

```markdown
| [UID:0002AK][0x0069ba3c-0x0069ba40.SurfacePresentationTempSurfaceSlot](by-memory/0x0069ba3c-0x0069ba40.SurfacePresentationTempSurfaceSlot.md) | emits | `0000OC` | `0000OC` |  | no | `auto-generated/NexusTK/render/Surface.cpp` | `by-memory/0x0069ba3c-0x0069ba40.SurfacePresentationTempSurfaceSlot.md` |  |
```

## Validation / Lease State

- Files edited by Agent-B001 in this assignment: this research report only.
- No by-* files were edited, per assignment instruction.
- `by-memory/-coverage-report.md` was not edited directly.
- Normal validator was not run because no in-scope by-* documentation file was changed by this agent; supervisor should run normal file validation after applying the recommended target/shared-report edits.
- Report-only checks: ASCII check passed; trailing whitespace check passed; report file exists at the required Agent-B001 research-root path.
- Git diff validation was unavailable in this workspace copy because neither `E:\NTK\GhidraBridge` nor `E:\NTK\GhidraBridge\source-3` exposes a `.git` repository.
- Lease state before report creation: `tools/leaser/Agents/current_leases.md` showed no active leases.
- Closeout lease check: Agent-B001 holds no leases, and no lease is held on the target page, `by-memory/-coverage-report.md`, or this report. Unrelated Agent-A001 leases appeared after report creation on separate by-class/by-file paths.
- Lease acquired: none, because only the B001 research report was created.

## Confidence

- Label/text repair: `95/95`. The scanner complaint is exact, and the target body/title lacks the compact token.
- Range boundary: `92/94`. Live IDA xrefs isolate `0x0069ba3c` between unrelated `0x0069ba38` and `0x0069ba40` users.
- Owner/emitter route: `90/88`. All four target xrefs are inside the Surface-owned `0x00558840-0x00558f63` initializer, and related docs already route that initializer to [UID:0000OC] `Surface`.
- Byte evidence correction: `96/95`. IDA MCP returns zero bytes/zero global value, and PE section mapping proves the target is in `.data` virtual zero-fill beyond raw-backed initialized bytes.
- Final source variable/type name: `75/80`. `SurfacePresentationTempSurfaceSlot` is a useful generated/report label, but not proven as the original source identifier. Keep C++ blank.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/0002AK-SurfacePresentationTempSurfaceSlot-memory-range-report.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:21","uid":"0002AK"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
