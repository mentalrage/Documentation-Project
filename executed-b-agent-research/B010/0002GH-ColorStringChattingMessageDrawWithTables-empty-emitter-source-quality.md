# UID0002GH ColorStringChattingMessage::Draw With Tables Empty-Emitter Source-Quality Report
** TARGET-REPORT-UID:0002GH **
** AUTHOR-AGENT-ID:B010 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **


## Finalized Report / Current Recommendation

This report recommends source reconstruction of the virtual `ColorStringChattingMessage::Draw` method at `0x004836a0` in `Chatting.cpp`, preservation of the compiler-emitted switch tables and alignment byte as non-source artifacts, and one narrowly bounded IDA function identity update. The target is source-ready at recommended confidence `94/96`. UID0002GH retains direct canonical owner/emitter UID00002Z; that class retains canonical owner/emitter UID0000I5, the Chatting file route. The child does not become an independent source file.

The recommendation covers the complete Draw ABI, both asset-mode branches, caller-owned rectangle mutation, palette override and restoration order, legacy frame selection, vtable liveness, compiler table ownership, formal C++/H placement, and exact support-document dependencies. After Gate 1 acceptance and the explicit implementation callback, B010 incorporated the accepted ordinary-document claims into exactly seven target/support by-* documents and ran their allocated scoped validators. B010 did not edit generated source, tracker, coverage, lifecycle, audit, or IDA state. Generated CPP/H remain at pre-callback command `000000023511` because every allocated validator explicitly used `--no-generated-refresh`; current generated-readback claims are recorded as blocked rather than falsely completed until supervisor-authorized refresh occurs.

## Supporting Research

- Agent: B010, fixed ChatGPT 5.6 xHigh assignment.
- Assignment: UID0002GH, `by-memory/0x004836a0-0x004839c0.ColorStringChattingMessageDrawWithTables.md`.
- Required workflow: project-level `ntk-b-agent-workflow`.
- Historical read-only research IDA session: `supervisor-uid0000KZ-rollback2-20260814`; this dated identity is provenance only and is not Gate 2B runtime authority.
- Exact IDB: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`.
- Runtime attestation: healthy Hex-Rays and string services; executable SHA256 `9AEC210BBC5CE592176A21DD8E9D9FD8F250B8D9EA78237915A99BA8CFA9A632`.
- Pre-callback target document: SHA256 `69A100E4CEA6B72CAEDD6FA8A488E0399F0CFE1ADF44AC727848954CDBEF3972`, `9913` bytes, `75` physical lines.
- Pre-callback class document `by-class/ColorStringChattingMessage.md`: SHA256 `9CBE532F86D7F427BE8C011A990B98BE529F070CAC7EEF0496F133962E0309A7`, `25535` bytes, `167` physical lines.
- Pre-callback file document `by-file/Chatting.md`: SHA256 `DB96C38CD2B6FACB2D4C192AE8D98417782F0CF2072EA341C93350F6230289CD`, `174697` bytes, `556` physical lines.
- Superseded generated research snapshot: command `000000023348` at `2026-08-14T03:21:40-04:00`; `Chatting.cpp` SHA256 `7945A5C78725FB38FE67BFF0E09A78EC1320CE7706F511BEA33AF6CFFD559470`, `78863` bytes, `2424` lines; `Chatting.h` SHA256 `B302430CC2B664C931D05B56189B92E4B3ABD679B638B99A015BDB265C9D537C`, `1444` bytes, `40` lines.
- Freeze-time current generated readback: command `000000023354` at `2026-08-14T03:30:45-04:00`; `Chatting.cpp` SHA256 `662A3719FEBC445089F120A4E17D3246DB0B34F1FF6E7EFDF39BB8A5E9769E08`, `78863` bytes, `2424` lines; `Chatting.h` SHA256 `E374317B112C0DFFB61BD300E077CAB00B9F1C73B2AFBC8B3A205483CDE9DC03`, `1444` bytes, `40` lines. The UID0002GH empty marker and class declaration remain present; callback must still dynamically reread generated authority.
- Post-callback ordinary documents: target `32D1551F40A60EC5CCBB53A94A2939DF45CCA37CF52132D50FD9281A4E300AE3` (`20947` bytes / `194` lines); ColorStringChattingMessage class `3FA3A1E8E343DC0179E7E8A7CE8333D3CDA93D6D2BEC4E093D0D3720CBBE67EF` (`28429` / `180`); Chatting file `0A37BC73BE125AAF85FD3D494CC515B1925D3C3DB062F8B5CEF6F916ED0418C5` (`177530` / `566`); MapColor `985C26D95009ACA03F3CCD027E58E297BDACE1EC33BA207EA5865ED735D0E796` (`5959` / `83`); SetColor `3D009B77DFB3EF096997F6877FA51AC7D422942EB1361ED1123D11F37AEF14A6` (`7126` / `103`); DLPalette class `1DA6C3E546ECE27EF9A5B0A4B3149C90AF95A8E51C7BC5A2A65CF6B00BC27C75` (`32004` / `226`); GrafPort class `26F685876E1955D4C495440862112FF2CB7CAF3AC93115219D48D3FA10657A5F` (`85460` / `547`).
- Post-callback generated readback remains command `000000023511` at `2026-08-14T04:57:37-04:00`: Chatting.cpp `16E0B88D6C180C33920AEBAC38957030022B9A1480DB2FF274B2D1A684C66C71`, Chatting.h `3264823EF525832EEE6AC926B5103C2016AAEFBC6394418A64469F7131055FDF`, Palette.cpp `8B9D688ECCA5469C939001AB047D5488B56DA0814ABD13046DC13AA2960571A7`, Palette.h `75A85FA0E7A4643F021E526C8917B39891225260D2DA9A9F675025214CF4169C`, GrafPort.cpp `DD2E22EF390F8958B8F91F1FE00D546D237721CB16F7B210D56AE952336FDF79`, and GrafPort.h `501F11B0D4B8D28890464F8BA72E67F82F036322ABFCBC79DE80EBEDA394EDF5`. Chatting.h retains the exact declaration once; the new Draw/MapColor/SetColor definitions, two palette declarations, and two GrafPort setters are not yet present because generated refresh is supervisor-owned.

## Target

| Item | Exact identity |
| --- | --- |
| UID | `0002GH` |
| Current documentation range | `[0x004836a0,0x004839c0)` |
| Function | `sub_4836A0`, `[0x004836a0,0x0048391c)`, `0x27c` / `636` bytes |
| Compiler jump table | `jpt_483894`, `[0x0048391c,0x00483930)`, `20` bytes |
| Compiler selector table | `byte_483930`, `[0x00483930,0x004839bf)`, `143` bytes |
| Tail alignment | `[0x004839bf,0x004839c0)`, one `CC` byte |
| Proposed source identity | `ColorStringChattingMessage::Draw(GrafPort *, RectBounds *)` |
| Source owner/emitter | UID0002GH -> UID00002Z class -> UID0000I5 file -> `Chatting.cpp` / `Chatting.h` |

## Current Target State

Before callback, the target page was an empty-emitter child at `86/92` with blank formal C++/H. It now scores `94/96`, contains the accepted source-ready formal CPP, keeps child H blank under UID00002Z class ownership, and preserves the UID00002Z -> UID0000I5 route. The generated `Chatting.cpp` snapshot still carries the old empty marker only because command `23516` skipped generated refresh by design; `Chatting.h` already carries the exact class-owned virtual declaration once.

IDA currently models `0x004836a0` as `sub_4836A0` with type `int __thiscall(int this, int, _DWORD *)`. The address comment, function comment, and both repeatable comments are blank. The body is a modeled function, the two tail tables are data, the final byte is alignment, and `sub_4839C0` begins exactly at `0x004839c0`. Literal `type_inspect` reports `ColorStringChattingMessage` as an opaque declaration-only local type with the unknown-size sentinel and no UDT members; no split, function definition, table materialization, declaration, or UDT completion is warranted.

Exact class-owned concrete layout:

| Offset | Field |
| ---: | --- |
| `+0x00` | primary vptr |
| `+0x04` | `wchar_t *m_text` |
| `+0x08` | `int m_foregroundColor` |
| `+0x0c` | `int m_backgroundColor` |
| `+0x10` | `unsigned char m_textStyleFlag` |
| `+0x14` | `int m_customForegroundRgb` |
| `+0x18` | `int m_customBackgroundRgb` |

The concrete size is `0x1c`; natural padding after the byte at `+0x10` places the next integer at `+0x14`.

## Executive Recommendation

1. Put the complete method body in the UID0002GH formal CPP block for incorporation by UID00002Z and final emission through UID0000I5 into `Chatting.cpp`.
2. Keep the child H formal block blank because `ColorStringChattingMessage.md` owns the declaration.
3. Preserve the exact existing class declaration and six-field `0x1c` layout.
4. Route `MapColor` and `SetColor` through their DLPalette child/owner documents and add two public inline GrafPort mode setters through the GrafPort owner.
5. Rename and type only the existing function at `0x004836a0`, using a pure rename and one regular function comment.
6. Protect the prepad, both compiler tables, tail byte, vtable slot, and successor function with exact no-change readbacks.

B010 owns all ordinary target/support by-* incorporation and its scoped validators after an explicit callback. Supervisor ownership is limited to manual coverage, Gate 2B IDA runtime work, independent verification, and lifecycle.

## Supervisor Active Recheck

Before Gate 2A/Gate 2B acceptance, the supervisor must dynamically reread the seven post-callback ordinary documents and the latest generated source. Commands `000000023348` and `000000023354` remain pre-callback history; command `000000023511` is the latest generated snapshot but predates all seven scoped callback validators. The supervisor must authorize a coherent generated refresh before treating C2GH-055/C2GH-057 through C2GH-061 as complete, then compare the refreshed definitions/declarations and hashes rather than relying on B010's stale generated snapshot.

The read-only IDA facts in this report were collected from the canonical exact IDB and are bounded by explicit byte identities. Any mismatch in function range, body hash, table bytes, vtable target, frame schema, collision query, or protected neighbor state is a stop condition. Supervisor runtime attestation, backup, mutation, save, persisted readback, and rollback remain outside this report.

## Inference Research Guidance Check

The target was checked against all relevant inference hazards:

- Virtual dispatch explains the absence of ordinary direct callers.
- The vtable slot, concrete constructor layout, class declaration, and ChattingPane paint calls jointly establish class identity and ABI.
- The table bytes are compiler lowering for a sparse switch, not hand-authored source data.
- Residual EAX in the legacy default path is not a source return value because the virtual ABI is void.
- The two local `0x28` records have layout-compatible use at one boundary but retain distinct semantic types.
- Direct protected GrafPort field stores are reconstructed with owner-supplied inline setters rather than invented friendship.
- Palette pointer ownership is borrowed; no release is added.
- String-length loops are faithfully represented by separate `wcslen` evaluations at each draw site.

## Heuristic / Inference Reanalysis And Validation

The prior heuristic label `class method with compiler tail data` remains correct, but the source-quality conclusion is strengthened. Function identity is not inferred from a name alone: the sole incoming data xref is the ColorStringChattingMessage primary vtable Draw slot, and ChattingPane invokes slot `+0x14` after slot `+0x10` on both current and legacy paint paths. The concrete object fields consumed by the body exactly match the class-owned layout.

The sparse legacy switch was reanalyzed from both tables and control flow. Keys `1`, `12`, and `143` select frames `2`, `1`, and `0`. Selector key `5` has a distinct selector value but reaches the same shared default return as all unsupported keys; a source-level explicit empty case 5 is behaviorally indistinguishable and unsupported by positive lexical evidence. Three cases plus `default: return;` is the least invented exact source.

The `g_useEpfAssets` test is equality with literal one, not generic nonzero truth. The current branch creates and initializes an otherwise unused local context before text drawing. That observable constructor call is retained. The style path performs two independent length scans and mutates the caller's bounds by `(+1, 0)` between draws without restoration. The custom-color path changes both palette entries whenever either override is nonzero, then restores entries before restoring the GrafPort palette pointer.

No reasonable blocker remains. Unknown original local names and an explicit source-level case 5 cannot be recovered, but neither affects exact behavior or placement.

## Evidence Standards Used

Positive claims require at least one exact IDA artifact and one corroborating source/documentation artifact where available. Negative claims use bounded searches, complete xref sets, collision lookups, exact range inspection, and exact bytes rather than absence by casual search. Inferred names are separated from proven ABI and behavior. Every proposed IDA delta has an exact prestate, permitted delta, expected readback, and stop condition.

Hashes are SHA256 over the exact stated byte interval or file bytes. Ranges are half-open. Sizes are decimal unless prefixed with `0x`. Generated evidence is timestamped because it can advance independently.

## Evidence Checked

- Fresh decompile, disassembly, function lookup, range inspection, frame, comments, xrefs, and bytes for `0x004836a0`.
- Exact proposed-name collision lookup.
- Exact jump-table and selector-table items, comments, xrefs, values, and hashes.
- Exact prepad, tail alignment, vtable slot, six-slot vtable span, and successor function boundaries.
- Fresh ChattingPane paint decompile covering both virtual Draw calls.
- Relevant EPF, GrafPort, palette, rectangle, and resource-layout callees.
- Current target, class, by-file, generated, helper, and manual coverage documents.
- Positive owner/emitter evidence and negative alternate-owner/emitter searches.
- Current and legacy behavior, field offsets, palette ownership, and restoration ordering.

## Claim And Incorporation Ledger

| Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C2GH-001 | 0002GH | UID0002GH route: Retain direct owner/emitter UID00002Z and class-to-file owner/emitter UID0000I5. Empty-emitter child does not gain a separate source file. | 99 | target, class, file, and generated ownership evidence; actor allocation: B010 ordinary target/support by-* implementation; Supervisor independent verification. | target Metadata / Ownership | incorporate | applied |
| C2GH-002 | 0002GH | UID0002GH function body: Record exact body identity and preserve bytes. Tables begin after the function. | 99 | `[0x004836a0,0x0048391c)`, 636 bytes, SHA256 `DF4DFC2018D31D28EEF3DAE2A168A8A813E75B440911EFAA9617EA10B9EC3DAA`; actor allocation: B010 ordinary by-* documentation; Supervisor Gate 2B IDA precheck/no-change readback and independent verification. | target IDA / Range | incorporate | applied |
| C2GH-003 | 0002GH | Draw ABI: Use `void __thiscall ColorStringChattingMessage::Draw(GrafPort *, RectBounds *)`. Current `int __thiscall(int this, int, _DWORD *)` pretype is incomplete. | 99 | vtable slot, class declaration, frame, virtual callers; actor allocation: B010 ordinary by-* documentation; Supervisor Gate 2B IDA precheck/no-change readback and independent verification. | target Formal / IDA | incorporate | applied |
| C2GH-004 | 0002GH | concrete layout: Record size `0x1c` and fields at `+00,+04,+08,+0c,+10,+14,+18`. No complete IDA UDT mutation. | 98 | constructor/class fields and target accesses; actor allocation: B010 ordinary by-* documentation; Supervisor Gate 2B IDA precheck/no-change readback and independent verification. | target Formal / class doc | incorporate | applied |
| C2GH-005 | 0002GH | current-mode entry: Preserve `g_useEpfAssets == true` and initialized otherwise-unused EPFTileContext. Generic nonzero test is not exact. | 99 | equality test and first call; actor allocation: B010 ordinary target/support by-* implementation; Supervisor independent verification. | target Formal CPP | incorporate | applied |
| C2GH-006 | 0002GH | current-mode setup: Set text draw mode 1 and foreground text color. Use GrafPort owner setter. | 98 | stores/calls before branch; actor allocation: B010 ordinary target/support by-* implementation; Supervisor independent verification. | target Formal CPP | incorporate | applied |
| C2GH-007 | 0002GH | style path: Draw, offset caller bounds `(1,0)`, reset mode/colors, and draw again. Bounds are not restored. | 99 | two draw blocks and RectBounds call; actor allocation: B010 ordinary target/support by-* implementation; Supervisor independent verification. | target Formal CPP | incorporate | applied |
| C2GH-008 | 0002GH | ordinary outlined path: Set background color and draw outlined text once. Applies when both override fields are zero. | 98 | zero-override branch; actor allocation: B010 ordinary target/support by-* implementation; Supervisor independent verification. | target Formal CPP | incorporate | applied |
| C2GH-009 | 0002GH | RGB override trigger: When either override is nonzero, rewrite both palette entries from packed RGB bytes. High/middle/low bytes map to R/G/B. | 98 | OR test and six component extracts; actor allocation: B010 ordinary target/support by-* implementation; Supervisor independent verification. | target Formal CPP | incorporate | applied |
| C2GH-010 | 0002GH | palette transaction: Save entries, set colors, save/install palette, draw, restore entries, restore palette. No palette release. | 99 | call order and borrowed pointer use; actor allocation: B010 ordinary target/support by-* implementation; Supervisor independent verification. | target Formal CPP | incorporate | applied |
| C2GH-011 | 0002GH | text lengths: Evaluate text length independently at each source draw call. Style path scans twice. | 98 | four independent inline scan loops; actor allocation: B010 ordinary target/support by-* implementation; Supervisor independent verification. | target Formal CPP | incorporate | applied |
| C2GH-012 | 0002GH | legacy frame mapping: Map `143->0`, `12->1`, `1->2`. Order may follow decompile without behavior change. | 99 | switch control flow and table decode; actor allocation: B010 ordinary target/support by-* implementation; Supervisor independent verification. | target Formal CPP | incorporate | applied |
| C2GH-013 | 0002GH | legacy default: Use bare default return for every other key. Do not return residual EAX. | 99 | void ABI and shared return block; actor allocation: B010 ordinary target/support by-* implementation; Supervisor independent verification. | target Formal CPP | incorporate | applied |
| C2GH-014 | 0002GH | legacy drawing: Initialize context, lookup `CHATBACK.EPD`, set draw mode 0, tile with `NP`, then draw text. Use explicit one-boundary record cast. | 98 | resource lookup and draw calls; actor allocation: B010 ordinary target/support by-* implementation; Supervisor independent verification. | target Formal CPP | incorporate | applied |
| C2GH-015 | 0002GH | jump table: Classify as compiler-emitted switch data and preserve unchanged. No handwritten table. | 99 | `[0x0048391c,0x00483930)` exact dwords and hash; actor allocation: B010 ordinary by-* documentation; Supervisor Gate 2B IDA precheck/no-change readback and independent verification. | target Range / IDA protection | incorporate | applied |
| C2GH-016 | 0002GH | selector table: Classify as compiler-emitted switch data and preserve unchanged. Key 5 shares default behavior. | 99 | `[0x00483930,0x004839bf)` exact selector values and hash; actor allocation: B010 ordinary by-* documentation; Supervisor Gate 2B IDA precheck/no-change readback and independent verification. | target Range / IDA protection | incorporate | applied |
| C2GH-017 | 0002GH | table source status: Emit no table declaration or definition. Compiler regenerates both tables. | 99 | switch lowering and no source consumer; actor allocation: B010 ordinary target/support by-* implementation; Supervisor independent verification. | target Formal CPP / H | incorporate | applied |
| C2GH-018 | 0002GH | tail alignment: Preserve one-byte alignment and exclude from source. Successor starts at `0x004839c0`. | 99 | `[0x004839bf,0x004839c0)` = `CC`; actor allocation: B010 ordinary by-* documentation; Supervisor Gate 2B IDA precheck/no-change readback and independent verification. | target Range / IDA protection | incorporate | applied |
| C2GH-019 | 0002GH | complete target pocket: Record exact complete range identity. Function, tables, and tail. | 99 | 800 bytes SHA256 `97E2EA981E07E0DB79783BC4528DB44B9E144E2C4828A71968A4D4F8B999A654`; actor allocation: B010 ordinary by-* documentation; Supervisor Gate 2B IDA precheck/no-change readback and independent verification. | target Range | incorporate | applied |
| C2GH-020 | 0002GH | boundaries: Preserve start/end; do not split, merge, or define functions. Current modeling is correct. | 99 | six-byte CC prepad and successor function; actor allocation: B010 ordinary by-* documentation; Supervisor Gate 2B IDA precheck/no-change readback and independent verification. | target Range | incorporate | applied |
| C2GH-021 | 0002GH | vtable slot: Record Draw as primary vtable slot `+0x14`. Cell bytes remain unchanged. | 99 | cell `0x00615280` points to target; six-slot vtable evidence; actor allocation: B010 ordinary by-* documentation; Supervisor Gate 2B IDA precheck/no-change readback and independent verification. | target Xrefs / Class | incorporate | applied |
| C2GH-022 | 0002GH | ChattingPane calls: Document both current-width and legacy-width paint consumers. Measure slot `+0x10` precedes Draw. | 98 | `0x0047fa4c` and `0x0047fb75` virtual calls; actor allocation: B010 ordinary target/support by-* implementation; Supervisor independent verification. | target Callers | incorporate | applied |
| C2GH-023 | 0002GH | virtual liveness: Treat vtable dispatch as live use, not dead code. No direct-call wrapper required. | 99 | zero direct code callers and one vtable data xref; actor allocation: B010 ordinary target/support by-* implementation; Supervisor independent verification. | target Callers / Negative evidence | incorporate | applied |
| C2GH-024 | 0002GH | callee inventory: Record all 14 semantic callees plus the security-cookie helper. Supports behavior and owner routing. | 98 | complete bounded call profile; actor allocation: B010 ordinary target/support by-* implementation; Supervisor independent verification. | target Dependencies | incorporate | applied |
| C2GH-025 | 0002GH | dependency ownership: Keep consumers as dependencies, not alternate emitters. No third-party import. | 97 | existing EPF/GrafPort/DLPalette/ResourceLayout owners; actor allocation: B010 ordinary target/support by-* implementation; Supervisor independent verification. | support docs | incorporate | applied |
| C2GH-026 | 0002GH | source placement: Place method in `Chatting.cpp` and declaration in class-owned `Chatting.h`. No new translation unit. | 99 | class and by-file routing; actor allocation: B010 ordinary target/support by-* implementation; Supervisor independent verification. | target/class/file Metadata | incorporate | applied |
| C2GH-027 | 0002GH | target CPP: Replace blank formal CPP with the recommendation in this report. Human-quality source, no decompiler temporaries. | 96 | complete behavior reconstruction; actor allocation: B010 ordinary target/support by-* implementation; Supervisor independent verification. | target Formal CPP | incorporate | applied |
| C2GH-028 | 0002GH | target H: Keep child formal H blank and state class ownership. Avoid duplicate declaration. | 99 | class document already owns declaration; actor allocation: B010 ordinary target/support by-* implementation; Supervisor independent verification. | target Formal H | incorporate | applied |
| C2GH-029 | 00002Z | UID00002Z class document: Preserve declaration/layout; add Draw behavior/source-ready evidence. UID00002Z remains target's direct owner/emitter. | 98 | complete declaration and layout; actor allocation: B010 ordinary target/support by-* implementation; Supervisor independent verification. | `by-class/ColorStringChattingMessage.md` | incorporate | applied |
| C2GH-030 | 0000I5 | UID0000I5 file document: Add target formal block and evidence; preserve all other source. Class-level owner/emitter remains UID0000I5. | 98 | existing Chatting aggregation; actor allocation: B010 ordinary target/support by-* implementation; Supervisor independent verification. | `by-file/Chatting.md` | incorporate | applied |
| C2GH-031 | 0004HQ | UID0004HQ DLPalette::MapColor: Add exact CPP and H declaration through its own route. Returns zero for index above 255. | 96 | exact child behavior and current blank formal source; actor allocation: B010 ordinary target/support by-* implementation; Supervisor independent verification. | MapColor child and UID00003Z DLPalette owner | incorporate | applied |
| C2GH-032 | 0004HR | UID0004HR DLPalette::SetColor: Add exact CPP and H declaration through its own route. Normalizes components 1..7 to 8. | 96 | exact child behavior and current weak type; actor allocation: B010 ordinary target/support by-* implementation; Supervisor independent verification. | SetColor child and UID00003Z DLPalette owner | incorporate | applied |
| C2GH-033 | 00005V | UID00005V GrafPort mode setters: Add public inline `SetDrawMode` and `SetTextDrawMode` setters. Exact single-byte stores. | 95 | direct protected stores in target; actor allocation: B010 ordinary target/support by-* implementation; Supervisor independent verification. | GrafPort owner H | incorporate | applied |
| C2GH-034 | 0002GH | record-type boundary: Keep EPFTileContext local and cast only at DrawTiledBackground call. Do not collapse global types. | 96 | both records size `0x28` but distinct semantics; actor allocation: B010 ordinary target/support by-* implementation; Supervisor independent verification. | target Formal CPP | incorporate | applied |
| C2GH-035 | 0002GH | target score: Raise target to `94/96 very-strong`. Residual uncertainty is lexical only. | 96 | exact ABI, behavior, bytes, tables, callers, placement; actor allocation: B010 ordinary target/support by-* implementation; Supervisor independent verification. | target Metadata / coverage | incorporate | applied |
| C2GH-036 | 00002Z | class score: Retain `90/93 very-strong`. Add evidence without score inflation. | 98 | declaration/layout already complete; actor allocation: B010 ordinary target/support by-* implementation; Supervisor independent verification. | class Metadata / coverage | incorporate | applied |
| C2GH-037 | 0000I5 | file score: Retain `89/93 very-strong`. Add target evidence without score inflation. | 98 | placement/emitter already strong; actor allocation: B010 ordinary target/support by-* implementation; Supervisor independent verification. | file Metadata / coverage | incorporate | applied |
| C2GH-038 | 0002GH | by-memory coverage row: Replace row with exact text in Section 28. Supervisor-owned callback only. | 96 | current UID row and this report; actor allocation: Supervisor manual coverage implementation and independent verification. | `by-memory/-coverage-report.md` | incorporate | proposed |
| C2GH-039 | 00002Z | by-class coverage row: Replace row with exact text in Section 28. Supervisor-owned callback only. | 96 | current UID00002Z row and this report; actor allocation: Supervisor manual coverage implementation and independent verification. | `by-class/-coverage-report.md` | incorporate | proposed |
| C2GH-040 | 0000I5 | by-file coverage row: Append exact clause in Section 28. Preserve existing row text. | 96 | current Chatting row and this report; actor allocation: Supervisor manual coverage implementation and independent verification. | `by-file/-coverage-report.md` | incorporate | proposed |
| C2GH-041 | 0002GH | I01 function identity: Apply only the bounded rename/type/comment delta after all prechecks. Runtime action is supervisor-owned. | 99 | exact prestate, collision, frame, body, comments; actor allocation: Supervisor Gate 2B IDA precheck/application/readback and independent verification. | IDA `0x004836a0` | incorporate | proposed |
| C2GH-042 | 0002GH | I01 pure rename: Require current MCP rename with `pure:true`; prohibit ordinary rename effects. No `/vibe/` state or refresh side effects. | 99 | proposed-name collision result `Not found`; actor allocation: Supervisor Gate 2B IDA precheck/application/readback and independent verification. | IDA rename operation | incorporate | proposed |
| C2GH-043 | 0002GH | P01 prepad: Read back byte-identical, otherwise stop without save. Protected no-change row. | 99 | six CC bytes and exact hash; actor allocation: Supervisor Gate 2B IDA precheck/application/readback and independent verification. | IDA `[0x0048369a,0x004836a0)` | already-present | proposed |
| C2GH-044 | 0002GH | P02 jump table: Read back all state unchanged, otherwise stop without save. Protected no-change row. | 99 | exact item, comments, xref, bytes, hash; actor allocation: Supervisor Gate 2B IDA precheck/application/readback and independent verification. | IDA `[0x0048391c,0x00483930)` | already-present | proposed |
| C2GH-045 | 0002GH | P03 selector table: Read back all state unchanged, otherwise stop without save. Protected no-change row. | 99 | exact item, comments, xref, bytes, hash; actor allocation: Supervisor Gate 2B IDA precheck/application/readback and independent verification. | IDA `[0x00483930,0x004839bf)` | already-present | proposed |
| C2GH-046 | 0002GH | P04 tail byte: Read back all state unchanged, otherwise stop without save. Protected no-change row. | 99 | unnamed CC item with blank metadata and zero xrefs; actor allocation: Supervisor Gate 2B IDA precheck/application/readback and independent verification. | IDA `[0x004839bf,0x004839c0)` | already-present | proposed |
| C2GH-047 | 0002GH | P05 vtable cell: Read back the complete cell identity unchanged, otherwise stop without save. No neighbor mutation. | 99 | data item `[0x00615280,0x00615284)`, blank name/type/comments, one outbound data xref, bytes/hash; actor allocation: Supervisor Gate 2B IDA precheck/application/readback and independent verification. | IDA vtable cell `[0x00615280,0x00615284)` | already-present | proposed |
| C2GH-048 | 0002GH | Callback implementation boundary: B010 changed exactly seven ordinary target/support by-* documents; generated source, manual coverage, tracker, lifecycle, audit, and IDA remained supervisor-owned and were not edited or mutated by B010. | 99 | post-callback changed-file hashes and validator command IDs `000000023516` through `000000023526`; generated command `000000023511` remained stale by the explicit no-refresh allocation; actor allocation: B010 ordinary implementation/report maintenance; Supervisor generated refresh, coverage, Gate 2, audit, and lifecycle. | callback boundary / Changed Files / Validator Results | incorporate | applied |
| C2GH-049 | 0002GH | IDA type prerequisite: Preserve the current opaque `ColorStringChattingMessage` local type exactly; no `declare_type`, UDT completion, or other prerequisite mutation. A pointer-qualified function type is sufficient. | 99 | literal `type_inspect`: exists true, declaration `ColorStringChattingMessage`, size `18446744073709551615`, is_func/is_ptr/is_enum/is_udt false, members null, member_count 0; actor allocation: Supervisor Gate 2B IDA precheck/no-change readback and independent verification. | IDA local type prerequisite | already-present | proposed |
| C2GH-050 | 0002GH | P06 successor function: Read back both code items, function identity, metadata, xrefs, bytes, and hash unchanged, otherwise stop without save. | 99 | `sub_4839C0 [0x004839c0,0x004839cb)`, two code items, exact comments/xrefs/bytes/hash; actor allocation: Supervisor Gate 2B IDA precheck/application/readback and independent verification. | IDA successor `[0x004839c0,0x004839cb)` | already-present | proposed |
| C2GH-051 | 0004HQ | UID0004HQ manual coverage: Insert the exact current-absent DLPalette::MapColor row from Section 28 without changing its 90/93 score, UID00003Z route, range, or reconstructable state. | 98 | literal current absence and exact insertion text in Section 28; actor allocation: Supervisor manual coverage implementation and independent verification. | `by-memory/-coverage-report.md` | incorporate | proposed |
| C2GH-052 | 0004HR | UID0004HR manual coverage: Insert the exact current-absent DLPalette::SetColor row from Section 28 without changing its 89/92 score, UID00003Z route, range, or reconstructable state. | 98 | literal current absence and exact insertion text in Section 28; actor allocation: Supervisor manual coverage implementation and independent verification. | `by-memory/-coverage-report.md` | incorporate | proposed |
| C2GH-053 | 00003Z | DLPalette owner manual coverage: Replace the exact current UID00003Z row with the Section 28 text adding MapColor/SetColor/SetPackedColor and child aggregation; retain score 92/94 and UID0000MA ownership. | 98 | literal current row, replacement row, and no-change disposition in Section 28; actor allocation: Supervisor manual coverage implementation and independent verification. | `by-class/-coverage-report.md` | incorporate | proposed |
| C2GH-054 | 00005V | GrafPort owner manual coverage: Replace the exact current UID00005V row with the Section 28 text adding the two public inline mode setters; retain score 88/90, 0xa0 layout, and UID0000JR ownership. | 98 | literal current row, replacement row, and no-change disposition in Section 28; actor allocation: Supervisor manual coverage implementation and independent verification. | `by-class/-coverage-report.md` | incorporate | proposed |
| C2GH-055 | 0002GH | Scoped target page validation after incorporation: validate while leased with generated refresh skipped, then verify newest Chatting.cpp contains the full Draw body and no empty marker. | 99 | literal command: `python .\tools\validator.py --mode file --file by-memory/0x004836a0-0x004839c0.ColorStringChattingMessageDrawWithTables.md --apply --no-generated-refresh --queue-timeout 240`; expect exit 0, ok:1, generated refresh skipped; actor allocation: B010 ordinary by-* implementation/validation; Supervisor independent verification. | target page validator / generated-current readback | incorporate | blocked |
| C2GH-056 | 00002Z | Scoped ColorStringChattingMessage owner validation after incorporation: validate while leased with generated refresh skipped, then verify newest Chatting.h retains the exact class declaration and virtual Draw. | 99 | literal command: `python .\tools\validator.py --mode file --file by-class/ColorStringChattingMessage.md --apply --no-generated-refresh --queue-timeout 240`; expect exit 0, ok:1, generated refresh skipped; actor allocation: B010 ordinary by-* implementation/validation; Supervisor independent verification. | ColorStringChattingMessage owner validator / generated-current readback | incorporate | applied |
| C2GH-057 | 0000I5 | Scoped Chatting file owner validation after incorporation: validate while leased with generated refresh skipped, then verify newest Chatting.cpp/Chatting.h emit the Draw definition/declaration exactly once. | 99 | literal command: `python .\tools\validator.py --mode file --file by-file/Chatting.md --apply --no-generated-refresh --queue-timeout 240`; expect exit 0, ok:1, generated refresh skipped; actor allocation: B010 ordinary by-* implementation/validation; Supervisor independent verification. | Chatting file owner validator / generated-current readback | incorporate | blocked |
| C2GH-058 | 0004HQ | Scoped MapColor child validation after incorporation: validate while leased with generated refresh skipped, then verify newest Palette.cpp/Palette.h emit MapColor exactly once through UID00003Z. | 99 | literal command: `python .\tools\validator.py --mode file --file by-memory/0x00542ac0-0x00542adc.DLPaletteMapColor.md --apply --no-generated-refresh --queue-timeout 240`; expect exit 0, ok:1, generated refresh skipped; actor allocation: B010 ordinary by-* implementation/validation; Supervisor independent verification. | MapColor child validator / generated-current readback | incorporate | blocked |
| C2GH-059 | 0004HR | Scoped SetColor child validation after incorporation: validate while leased with generated refresh skipped, then verify newest Palette.cpp/Palette.h emit SetColor exactly once through UID00003Z. | 99 | literal command: `python .\tools\validator.py --mode file --file by-memory/0x00542ae0-0x00542b4a.DLPaletteSetColor.md --apply --no-generated-refresh --queue-timeout 240`; expect exit 0, ok:1, generated refresh skipped; actor allocation: B010 ordinary by-* implementation/validation; Supervisor independent verification. | SetColor child validator / generated-current readback | incorporate | blocked |
| C2GH-060 | 00003Z | Scoped DLPalette owner validation after incorporation: validate while leased with generated refresh skipped, then verify newest Palette.cpp/Palette.h contain all three coherent palette methods and declarations exactly once. | 99 | literal command: `python .\tools\validator.py --mode file --file by-class/DLPalette.md --apply --no-generated-refresh --queue-timeout 240`; expect exit 0, ok:1, generated refresh skipped; actor allocation: B010 ordinary by-* implementation/validation; Supervisor independent verification. | DLPalette owner validator / generated-current readback | incorporate | blocked |
| C2GH-061 | 00005V | Scoped GrafPort owner validation after incorporation: validate while leased with generated refresh skipped, then verify newest GrafPort header emits both inline mode setters exactly once and generated CPP remains coherent. | 99 | literal command: `python .\tools\validator.py --mode file --file by-class/GrafPort.md --apply --no-generated-refresh --queue-timeout 240`; expect exit 0, ok:1, generated refresh skipped; actor allocation: B010 ordinary by-* implementation/validation; Supervisor independent verification. | GrafPort owner validator / generated-current readback | incorporate | blocked |

Ledger count: `61` atomic claims. Allocation: `39/61` checked, `22/61` unchecked. The checklist in Section 33 mirrors all eight fields byte-for-byte after its leading Done column.
## Positive Evidence Summary

- The ColorStringChattingMessage primary vtable has six consecutive slots at `[0x0061526c,0x00615284)`; the last cell at `0x00615280` contains `0x004836a0`.
- The class declaration gives Draw the exact virtual signature `void Draw(GrafPort *, RectBounds *)`, and the concrete function consumes the documented `0x1c` field layout.
- ChattingPane paint calls MeasureLines at virtual slot `+0x10` and Draw at slot `+0x14` in both asset modes.
- Every visible branch is explained by current-mode text drawing or legacy `CHATBACK.EPD` drawing; no unexplained target calls remain.
- The custom palette path's save/mutate/install/draw/restore sequence is directly ordered by calls and data flow.
- Exact table values reproduce all sparse switch destinations and the shared default block.
- Existing ownership records consistently place the class in `Chatting.h` and methods in `Chatting.cpp`.

## IDA MCP Facts

| Fact | Exact read-only result |
| --- | --- |
| Function lookup | `sub_4836A0`, `[0x004836a0,0x0048391c)`, size `0x27c` |
| Current type | `int __thiscall(int this, int, _DWORD *)` |
| Body profile | `223` instructions, `24` basic blocks, zero ordinary callers |
| Body bytes | `636` bytes, SHA256 `DF4DFC2018D31D28EEF3DAE2A168A8A813E75B440911EFAA9617EA10B9EC3DAA` |
| Full target bytes | `800` bytes, SHA256 `97E2EA981E07E0DB79783BC4528DB44B9E144E2C4828A71968A4D4F8B999A654` |
| Current comments | address regular/repeatable and function regular/repeatable all blank |
| Proposed-name collision | literal lookup `ColorStringChattingMessage__Draw`: `fn:null`, `error:"Not found"` |
| `ColorStringChattingMessage` local type | literal `type_inspect`: exists, declaration-only opaque name, size `18446744073709551615`, not function/pointer/enum/UDT, no members; prerequisite action: none; expected poststate unchanged |
| Parameter local types | `GrafPort` UDT size 160 and `RectBounds` UDT size 16; prerequisite action: none; expected poststate unchanged |
| Incoming xrefs | one data xref from vtable cell `0x00615280`; no ordinary direct code caller |
| Prepad | `[0x0048369a,0x004836a0)` = six `CC` bytes; SHA256 `33CC4A00A0F04735602819132DA3E3FAC4CDEB8EC7AEE92551DC79BA8488E722` |
| Successor | `sub_4839C0`, `[0x004839c0,0x004839cb)`, type `void()`, hash `9522583BF93440680B9666758D5A9FFD30A81E34547BC80F041957F39A05D52A` |

Current exact frame:

| Name | Offset | Size | Type |
| --- | ---: | ---: | --- |
| `palette` | `+0x0c` | `0x04` | `DLPalette *` |
| `var_3C` | `+0x10` | `0x04` | `unsigned __int16[2]` |
| `var_38` | `+0x14` | `0x04` | `DLPalette *` |
| `packedColor` | `+0x18` | `0x04` | `unsigned __int16[2]` |
| `rect` | `+0x1c` | `0x04` | `RectBounds *` |
| `outContext` | `+0x20` | `0x28` | `EPFTileContext` |
| `var_4` | `+0x48` | `0x04` | `_DWORD` |
| `__saved_registers` | `+0x4c` | `0x04` | `_DWORD` |
| `__return_address` | `+0x50` | `0x04` | `_UNKNOWN *` |
| `arg_0` | `+0x54` | `0x04` | `GrafPort *` |
| `bounds` | `+0x58` | `0x04` | `RectBounds *` |

## Function / Child Inventory

| Address | Current identity | Source identity / role | Disposition |
| --- | --- | --- | --- |
| `0x004836a0` | `sub_4836A0` | `ColorStringChattingMessage::Draw` | Source-ready; bounded I01 identity update |
| `0x00457a60` | `EPFTileContext_Initialize` | context initialization | Existing dependency; called in both modes |
| `0x004b78f0` | `RectBounds_Offset` | caller-bounds offset | Existing dependency |
| `0x004b9680` | `GrafPort_SetTextColor` | foreground setter | Existing dependency |
| `0x004b9690` | `sub_4B9690` | `GrafPort::SetTextBackColor` | Existing formal method; IDA name/type repair belongs to owner |
| `0x004b96a0` | `GrafPort_GetPalette` | borrowed palette getter | Existing dependency |
| `0x004b96b0` | `GrafPort_SetPalette` | palette installer/restorer | Existing dependency |
| `0x004ba6b0` | `GrafPort_DrawTiledBackground` | legacy tiled background | Existing dependency |
| `0x004bad70` | `sub_4BAD70` | `GrafPort::DrawTextInRect` | Existing formal method; owner controls IDA identity |
| `0x004bafa0` | `GrafPort_DrawOutlinedText` | current outlined text | Existing dependency |
| `0x004d02f0` | `ResourceLayoutTable_LookupLayoutEntry` | `CHATBACK.EPD` frame lookup | Existing dependency |
| `0x00542ac0` | `DLPalette_MapColor` | palette entry getter | Formal CPP/H support callback required |
| `0x00542ae0` | `sub_542AE0` | `DLPalette::SetColor` | Formal CPP/H support callback required |
| `0x00542b50` | `DLPalette_SetPackedColor` | exact packed entry restore | Existing dependency |
| `0x00543d60` | `PaletteLib__GetTextPalette` | borrowed text palette | Existing dependency |
| `0x004839c0` | `sub_4839C0` | unrelated successor | Protected unchanged |

The security-cookie helper is compiler support and is not a source-owned child. No child listed above displaces UID00002Z ownership of Draw.

## Direct Xref / Caller Inventory

The complete target xref set contains no ordinary direct code callers and one incoming data xref from `0x00615280`. That cell is the final slot of the primary ColorStringChattingMessage vtable and points to `0x004836a0`.

`ChattingPane::OnPaint` at `0x0047f8d0` provides the concrete runtime consumers:

- Current asset path: virtual MeasureLines with width `783`, then virtual Draw at `0x0047fa4c`.
- Legacy asset path: virtual MeasureLines with width `408`, then virtual Draw at `0x0047fb75`.

Both calls pass the ChattingPane as the GrafPort object and a stack RectBounds. The target's `bounds->Offset(1, 0)` therefore mutates the caller-owned stack rectangle. A bounded search found no second concrete ChattingMessage Draw override and no direct wrapper.

## Documentation Evidence And IDA Status

The target document already identifies the broad current/legacy split and table tail but leaves formal source empty. The class document supplies the complete abstract ChattingMessage interface, the concrete ColorStringChattingMessage declaration, and exact fields. The by-file document owns the Chatting translation unit and emission route. The generated header includes the declaration; the generated CPP snapshot contains an empty target marker.

IDA has the correct function and data boundaries. Its current `int __thiscall(int this, int, _DWORD *)` type is incomplete at return, object, and explicit parameters; its local frame already has useful application types. The two table comments are existing IDA-generated descriptive comments and should remain untouched. Literal `type_inspect` proves `ColorStringChattingMessage` is an opaque declaration-only local type; pointer use requires no prerequisite mutation, and completing it would have unsafe global decompiler blast radius.

## Ranked Ownership Analysis

| Rank | Candidate | Evidence | Decision |
| ---: | --- | --- | --- |
| 1 | UID00002Z -> UID0000I5 -> `Chatting.cpp` / `Chatting.h` | target metadata, class metadata, by-file route, generated route, sibling methods, vtable identity | Exact direct-class then class-to-file owner/emitter chain |
| 2 | UID0002GH child | exact body/range research and formal block target | Research child only; empty-emitter incorporation source |
| 3 | GrafPort owner | owns mode setters and drawing APIs | Support owner, not Draw emitter |
| 4 | DLPalette owner and MapColor/SetColor children | own palette helper source | Support owner, not Draw emitter |
| 5 | EPF/resource-layout owners | provide legacy context and lookup | Dependencies only |

No alternate file has a stronger symbol, class, vtable, or generated-emitter claim. Creating `ColorStringChattingMessage.cpp` would fragment the established Chatting ownership route.

## Source Placement

- Formal CPP: UID0002GH block incorporated by direct owner/emitter UID00002Z, then emitted through UID00002Z's owner/emitter UID0000I5 into `Chatting.cpp`.
- Formal H: no child declaration. Preserve the declaration in `by-class/ColorStringChattingMessage.md` and emit it through `Chatting.h`.
- Support H: GrafPort owner for two inline setters; DLPalette owner for MapColor and SetColor declarations.
- Support CPP: MapColor and SetColor child formal blocks incorporated through the DLPalette owner.
- Compiler tables: no source placement; generated by the compiler from the switch.

## Range / Split / Padding / Reclassification Analysis

The exact target pocket is:

| Subrange | Classification | Exact identity |
| --- | --- | --- |
| `[0x004836a0,0x0048391c)` | function | 636 bytes, SHA256 `DF4DFC2018D31D28EEF3DAE2A168A8A813E75B440911EFAA9617EA10B9EC3DAA` |
| `[0x0048391c,0x00483930)` | jump table | 20 bytes, SHA256 `A64B3BF81649689C54387F441C95D98A4774C5F39B866E8B245D378D64D0DA29` |
| `[0x00483930,0x004839bf)` | selector table | 143 bytes, SHA256 `0ACDCE702936EAECA6DF5142EAED9C6334C1CD4920B2955E734133A4EC447119` |
| `[0x004839bf,0x004839c0)` | alignment | one `CC`, SHA256 `1DD8312636F6A0BF3D21FA2855E63072507453E93A5CED4301B364E91C9D87D6` |

The jump-table dwords are `004838a6, 00483909, 0048389f, 0048389b, 00483909`. The selector table is 143 bytes: index/key `1 -> 0`, `5 -> 1`, `12 -> 2`, `143 -> 3`, and every other key maps to selector `4`. Selectors 1 and 4 both reach `0x00483909`.

The aggregate table range `[0x0048391c,0x004839c0)` is 164 bytes with SHA256 `356BE1B3250B9A47B8FD0F17417C9CAE93916B8EB8FE4E616B8B6939C1418381`. Existing item names, comments, and xrefs are coherent. No range split, merge, code conversion, data conversion, or padding absorption is recommended.

## Negative Evidence Summary

- No direct code caller exists; this does not imply dead code because vtable and virtual-call evidence is complete.
- No proposed-name collision exists for `ColorStringChattingMessage__Draw`.
- No source-authored table declaration, table consumer, or reason to hand-emit either compiler table was found.
- No evidence supports a non-void Draw return despite residual EAX on the default block.
- No evidence supports generic nonzero interpretation of `g_useEpfAssets`.
- No evidence supports restoring the style-path caller bounds.
- No release or ownership transfer exists for the text-palette pointer.
- No second concrete ChattingMessage Draw implementation was found.
- No alternate translation unit or independent child emitter has ownership evidence.
- No complete IDA UDT is needed to type this function safely.
- No direct generated-file edit, third-party source import, lifecycle action, or tracker action belongs in research.

## IDA Rename / Type / Comment Recommendations

### Local-Type Prerequisite

| Field | Literal current read-only state | Required action and poststate |
| --- | --- | --- |
| `ColorStringChattingMessage` `type_inspect` | `exists:true`; declaration `ColorStringChattingMessage`; size `18446744073709551615`; `is_func:false`, `is_ptr:false`, `is_enum:false`, `is_udt:false`; `members:null`; `member_count:0` | No prerequisite action. Preserve this opaque local type exactly; do not call `declare_type`, complete a UDT, or change its declaration. |
| `ChattingMessage` `type_inspect` | Same opaque shape: exists, declaration-only name, unknown-size sentinel, no UDT members | No change; it is not needed by I01. |
| Parameter dependencies | `GrafPort` is a size-`160` UDT; `RectBounds` is a size-`16` UDT | No change. Existing pointer types are sufficient. |

The proposed pointer-qualified signature is safe against this exact prestate: current MCP semantics accept an opaque named local type behind a pointer, so no global type mutation is a prerequisite. Any different `ColorStringChattingMessage` `type_inspect` result stops the transaction with no save.

### I01 Actionable Function Row

| Field | Required exact state |
| --- | --- |
| Address/range | `0x004836a0` / `[0x004836a0,0x0048391c)` |
| Current identity/item | function `sub_4836A0`; entry item `[0x004836a0,0x004836a1)`, one-byte code |
| Current type | `int __thiscall(int this, int, _DWORD *)` |
| Current comments | entry address regular/repeatable and function regular/repeatable all blank |
| Current xrefs | outbound internal code `0x004836a0 -> 0x004836a1`; inbound data `0x00615280 -> 0x004836a0`; no ordinary direct caller |
| Current body | 636 bytes, SHA256 `DF4DFC2018D31D28EEF3DAE2A168A8A813E75B440911EFAA9617EA10B9EC3DAA` |
| Collision prestate | exact lookup `ColorStringChattingMessage__Draw` returns `fn:null` / `Not found` |
| Proposed name | `ColorStringChattingMessage__Draw` |
| Proposed type | `void __thiscall ColorStringChattingMessage__Draw(ColorStringChattingMessage *this, GrafPort *grafPort, RectBounds *bounds)` |
| Proposed function regular comment | `ColorStringChattingMessage::Draw; renders current EPF text or legacy CHATBACK.EPD background/text and restores temporary palette state.` |
| Other comments | preserve blank |
| Rename semantics | current MCP rename with `pure:true` only; ordinary rename and `/vibe/` or refresh/decompile side effects prohibited |
| Permitted frame delta | replace only `arg_0 +0x54 GrafPort *` with `grafPort +0x54 GrafPort *`; preserve all other ten rows; added rows 0, removed rows 0 |
| Byte delta | none |

### Protected No-Change Rows

| ID | Exact complete prestate | Required exact post-readback |
| --- | --- | --- |
| P01 | One data item `[0x0048369a,0x004836a0)`, size 6, blank name/type, data true/code false; address regular and repeatable comments blank at each of the six addresses; zero incoming/outgoing regular xrefs at each address; bytes `CC CC CC CC CC CC`; SHA256 `33CC4A00A0F04735602819132DA3E3FAC4CDEB8EC7AEE92551DC79BA8488E722`. | Same one data item/range/size/classification, blank name/type, all twelve address-comment fields blank, zero xrefs, identical six bytes, and identical SHA256. |
| P02 | One data item `jpt_483894 [0x0048391c,0x00483930)`, size 20, blank type, data true/code false; regular comment `jump table for switch statement`, repeatable comment blank; complete xrefs: inbound data `0x00483894 -> 0x0048391c`, outbound data to `0x0048389b`, `0x0048389f`, `0x004838a6`, and `0x00483909`; bytes `A6 38 48 00 09 39 48 00 9F 38 48 00 9B 38 48 00 09 39 48 00`; SHA256 `A64B3BF81649689C54387F441C95D98A4774C5F39B866E8B245D378D64D0DA29`. | Same data item/name/range/size/blank type, same regular and repeatable comments, same five complete xrefs, identical 20 bytes, and identical SHA256. |
| P03 | One data item `byte_483930 [0x00483930,0x004839bf)`, size 143, blank type, data true/code false; regular comment `indirect table for switch statement`, repeatable comment blank; sole inbound data xref `0x0048388d -> 0x00483930`, no outbound xrefs; bytes have index 0=`00`, 4=`01`, 11=`02`, 142=`03`, every other index=`04`; SHA256 `0ACDCE702936EAECA6DF5142EAED9C6334C1CD4920B2955E734133A4EC447119`. | Same data item/name/range/size/blank type, same regular and repeatable comments, same sole xref, identical selector bytes, and identical SHA256. |
| P04 | One data item `[0x004839bf,0x004839c0)`, size 1, blank name/type, data true/code false; regular/repeatable comments blank; zero incoming/outgoing xrefs; byte `CC`; SHA256 `1DD8312636F6A0BF3D21FA2855E63072507453E93A5CED4301B364E91C9D87D6`. | Same data item/range/size/classification, blank name/type/comments, zero xrefs, identical byte, and identical SHA256. |
| P05 | One data item `[0x00615280,0x00615284)`, size 4, blank name/type, data true/code false; regular/repeatable comments blank; one outbound data xref `0x00615280 -> 0x004836a0`, no inbound xrefs; bytes `A0 36 48 00`; SHA256 `92548BA999CE4AC9E43AA2114714BD7C3E5A1E0844A6555D919050AE46859A8E`. | Same data item/range/size/classification, blank name/type/comments, same sole outbound xref/no inbound xrefs, identical four bytes, and identical SHA256. |
| P06 | Function `sub_4839C0 [0x004839c0,0x004839cb)`, size `0x0b`, type `void()`; code item 1 `[0x004839c0,0x004839ca)`, size 10, name `sub_4839C0`, type `void()`; code item 2 `[0x004839ca,0x004839cb)`, size 1, blank name/type; entry address regular/repeatable and function regular/repeatable comments blank, tail address regular/repeatable comments blank; entry xrefs are inbound code `0x005fc2ce -> 0x004839c0`, outbound code `0x004839c0 -> 0x004839ca`, outbound data `0x004839c0 -> 0x0067ade0`; tail has the same internal inbound edge; bytes `C7 05 E0 AD 67 00 00 00 00 00 C3`; SHA256 `9522583BF93440680B9666758D5A9FFD30A81E34547BC80F041957F39A05D52A`. | Same function/range/size/type, same two code items with names/types, every listed address/function comment blank, same complete entry/tail xrefs, identical 11 bytes, and identical SHA256. |

### Exact Current-Schema Payloads

Let `DB` mean the exact `session_id` returned by the supervisor's fresh canonical `idb_open` of `E:\NTK\Resources\NexusTK\NexusTK.exe.i64` immediately before Gate 2B. `DB` is a metasyntactic token in the payloads below and must be replaced with that exact live session ID. No historical research-session ID is reusable runtime authority.

Before any entity precheck or mutation, call the public schema-1 `runtime_attestation` endpoint with `{"expected_database":"DB","expected_canonical_path":"E:\\NTK\\Resources\\NexusTK\\NexusTK.exe.i64"}` after substituting the exact live session ID for `DB`. Require top-level `schema_version:1`, `ok:true`, `errors:[]`, exact database/session and canonical-path matches, and current listener plus selected worker identities to agree with the live MCP runtime. Require the attested listener and worker module identities, origins, resolved paths, sizes, timestamps, and hashes for the currently loaded `ida_pro_mcp` and `zeromcp` implementation to agree with that runtime. A missing field, stale or mismatched listener/worker/module identity, wrong path/database, nonempty errors, or any schema mismatch stops before precheck, mutation, backup, or save.

- `rename` pure dry run: `{"database":"DB","batch":{"func":[{"addr":"0x004836a0","name":"ColorStringChattingMessage__Draw"}],"allow_overwrite":false,"dry_run":true,"pure":true,"stop_on_error":true}}`.
- `rename` pure apply: `{"database":"DB","batch":{"func":[{"addr":"0x004836a0","name":"ColorStringChattingMessage__Draw"}],"allow_overwrite":false,"dry_run":false,"pure":true,"stop_on_error":true}}`.
- `set_type` endpoint: `{"database":"DB","edits":[{"addr":"0x004836a0","kind":"function","signature":"void __thiscall ColorStringChattingMessage__Draw(ColorStringChattingMessage *this, GrafPort *grafPort, RectBounds *bounds)"}]}`.
- `set_function_comments` regular-comment endpoint: `{"database":"DB","items":[{"addr":"0x004836a0","comment":"ColorStringChattingMessage::Draw; renders current EPF text or legacy CHATBACK.EPD background/text and restores temporary palette state."}]}`.

The current `set_type` and `set_function_comments` schemas expose no overwrite, dry-run, or stop-on-error flags; those fields are explicitly not applicable and must not be invented. For `set_type`, require the exact pretype and stop externally on any endpoint error or type/frame delta beyond the permitted row rename. For the comment endpoint, the blank regular function-comment prestate is the no-overwrite guard; stop externally on a nonblank prestate, endpoint error, or any address/repeatable-comment delta.

### Deterministic Current-Schema Order

1. Supervisor freshly opens the exact canonical IDB, binds `DB` to the returned exact session ID, passes the public schema-1 `runtime_attestation` precondition above for that session/path and current listener/worker/module identities, then creates and verifies a clean byte-identical backup.
2. Read `ColorStringChattingMessage` `type_inspect`; require the literal opaque state and perform no prerequisite mutation.
3. Read I01 item/function/range, exact pretype, all four comment fields, complete frame, complete xrefs, and 636-byte hash; stop/no-save on mismatch.
4. Query literal destination `ColorStringChattingMessage__Draw`; require `fn:null` / `Not found`; stop/no-save on collision.
5. Read P01, P02, P03, P04, P05, then P06 field-for-field; stop/no-save on any mismatch.
6. Submit the exact pure-rename dry-run payload; require one function name-only delta, `allow_overwrite:false`, `pure:true`, and no `/vibe/`, refresh, or decompile side effect; stop/no-save otherwise.
7. Submit the exact pure-rename apply payload, then read back I01 name/range/body/comments/xrefs/frame and P01-P06; stop/no-save on any unlisted delta.
8. Submit the exact `set_type` payload, then require the exact signature and frame delta: only `arg_0 +0x54 GrafPort *` becomes `grafPort +0x54 GrafPort *`; added rows 0, removed rows 0; stop/no-save otherwise.
9. Recheck blank regular function comment, submit the exact function-comment payload, then require only that regular function comment to change; stop/no-save otherwise.
10. Read back I01 completely, including 636-byte hash and all four comment fields, then P01-P06 completely in order. Save only after every expected state matches; perform persisted readback after save.

At every step, any extra item, byte, name, type, frame, comment, xref, table, neighbor, local-type, or side-effect delta requires immediate stop with no save and rollback to the clean backup. The supervisor owns runtime attestation, backup, Gate 2B mutation, save, persisted readback, rollback, independent verification, and lifecycle outside the report. This report does not authorize independent execution.
## First-Draft C++ Recommendation

Target formal CPP:

```cpp
void ColorStringChattingMessage::Draw(GrafPort *grafPort, RectBounds *bounds)
{
    if (g_useEpfAssets == true) {
        EPFTileContext unusedContext;
        unusedContext.Initialize();

        grafPort->SetTextDrawMode(1);
        grafPort->SetTextColor(m_foregroundColor);

        if (m_textStyleFlag != 0) {
            grafPort->DrawTextInRect(m_text, static_cast<int>(wcslen(m_text)), bounds);
            bounds->Offset(1, 0);
            grafPort->SetTextDrawMode(1);
            grafPort->SetTextColor(m_foregroundColor);
            grafPort->SetTextBackColor(0);
            grafPort->DrawTextInRect(m_text, static_cast<int>(wcslen(m_text)), bounds);
            return;
        }

        grafPort->SetTextBackColor(m_backgroundColor);
        if (m_customForegroundRgb != 0 || m_customBackgroundRgb != 0) {
            DLPalette *textPalette = g_pPaletteLib->GetTextPalette();
            const unsigned short savedForeground = textPalette->MapColor(m_foregroundColor);
            const unsigned short savedBackground = textPalette->MapColor(m_backgroundColor);

            textPalette->SetColor(
                m_foregroundColor,
                static_cast<unsigned char>(m_customForegroundRgb >> 16),
                static_cast<unsigned char>(m_customForegroundRgb >> 8),
                static_cast<unsigned char>(m_customForegroundRgb));
            textPalette->SetColor(
                m_backgroundColor,
                static_cast<unsigned char>(m_customBackgroundRgb >> 16),
                static_cast<unsigned char>(m_customBackgroundRgb >> 8),
                static_cast<unsigned char>(m_customBackgroundRgb));

            DLPalette *savedPalette = grafPort->GetPalette();
            grafPort->SetPalette(textPalette);
            grafPort->DrawOutlinedText(m_text, static_cast<int>(wcslen(m_text)), bounds);
            textPalette->SetPackedColor(m_foregroundColor, savedForeground);
            textPalette->SetPackedColor(m_backgroundColor, savedBackground);
            grafPort->SetPalette(savedPalette);
            return;
        }

        grafPort->DrawOutlinedText(m_text, static_cast<int>(wcslen(m_text)), bounds);
        return;
    }

    EPFTileContext background;
    background.Initialize();

    int frameIndex;
    switch (m_backgroundColor) {
    case 143:
        frameIndex = 0;
        break;
    case 12:
        frameIndex = 1;
        break;
    case 1:
        frameIndex = 2;
        break;
    default:
        return;
    }

    g_pEPFLib->LookupLayoutEntry(L"CHATBACK.EPD", frameIndex, &background);
    grafPort->SetDrawMode(0);
    grafPort->DrawTiledBackground(
        bounds,
        reinterpret_cast<const FrameDrawRecord *>(&background),
        L"NP");
    grafPort->SetTextDrawMode(1);
    grafPort->SetTextColor(m_foregroundColor);
    grafPort->DrawTextInRect(m_text, static_cast<int>(wcslen(m_text)), bounds);
}
```

Target formal H: intentionally blank. The class owner already declares:

```cpp
class GrafPort;
struct RectBounds;

class ChattingMessage : public LObject
{
public:
    virtual ChattingMessage *Clone() = 0;
    virtual int MeasureLines(GrafPort *grafPort, int width) = 0;
    virtual void Draw(GrafPort *grafPort, RectBounds *bounds) = 0;
};

class ColorStringChattingMessage : public ChattingMessage
{
public:
    ColorStringChattingMessage(const wchar_t *text,
                               int foregroundColor,
                               int backgroundColor,
                               unsigned char textStyleFlag,
                               int customForegroundRgb,
                               int customBackgroundRgb);
    virtual ~ColorStringChattingMessage();
    virtual ChattingMessage *Clone();
    virtual int MeasureLines(GrafPort *grafPort, int width);
    virtual void Draw(GrafPort *grafPort, RectBounds *bounds);

private:
    wchar_t *m_text;
    int m_foregroundColor;
    int m_backgroundColor;
    unsigned char m_textStyleFlag;
    int m_customForegroundRgb;
    int m_customBackgroundRgb;
};
```

Required DLPalette support formal CPP/H through the existing child and owner routes:

```cpp
unsigned short DLPalette::MapColor(unsigned int colorIndex) const
{
    if (colorIndex > 0xff)
        return 0;
    return m_mappedColors[colorIndex];
}

void DLPalette::SetColor(
    unsigned int colorIndex,
    unsigned char red,
    unsigned char green,
    unsigned char blue)
{
    if (colorIndex > 0xff)
        return;

    if (red > 0 && red < 8)
        red = 8;
    if (green > 0 && green < 8)
        green = 8;
    if (blue > 0 && blue < 8)
        blue = 8;

    m_mappedColors[colorIndex] = g_pfnPackPixel(red, green, blue);
}
```

```cpp
unsigned short MapColor(unsigned int colorIndex) const;
void SetColor(
    unsigned int colorIndex,
    unsigned char red,
    unsigned char green,
    unsigned char blue);
```

Required GrafPort owner H additions:

```cpp
void SetDrawMode(unsigned char drawMode) { m_drawMode = drawMode; }
void SetTextDrawMode(unsigned char textDrawMode) { m_textDrawMode = textDrawMode; }
```

## Final Recommendation

Accept the method as source-ready once the target, class, file, support, coverage, and bounded IDA claims are incorporated through their existing owners. The formal source is behaviorally exact without imitating decompiler artifacts: it preserves the unusual initialized unused context, exact equality branch, repeated length scans, caller rectangle mutation, both-palette-entry override, restoration order, sparse legacy mapping, and bare void default return.

Do not emit compiler tables, duplicate the H declaration, create a new translation unit, complete global IDA UDTs, or broaden the IDA transaction. The former instruction to remain lifecycle-neutral "until supervisor callback" is historical and satisfied: the callback completed without any of those prohibited changes. Generated refresh, manual coverage, Gate 2A/2B, audit, report execution, and archive movement remain supervisor-owned.

## Recommended Target Doc Changes

1. Replace the blank formal CPP with the target method in Section 22.
2. Keep formal H blank and explicitly cite class ownership.
3. Replace stale broad behavior prose with exact current/legacy, palette, table, caller, field, and ABI evidence.
4. Record exact body, table, alignment, vtable, and successor identities.
5. Add I01 and P01-P06 as structured callback rows.
6. Raise the target recommendation to `94/96 very-strong`.

## Recommended Support Doc Changes

- `by-class/ColorStringChattingMessage.md`: preserve the declaration and layout; add complete Draw behavior, vtable slot, caller, and source-ready evidence.
- `by-file/Chatting.md`: add the target formal block and ownership evidence without disturbing existing methods.
- DLPalette MapColor child/owner: add exact getter CPP/H.
- DLPalette SetColor child/owner: add exact normalizing setter CPP/H and correct semantic return to void.
- GrafPort owner: add the two exact public inline one-byte mode setters.
- Manual coverage reports: apply only the exact supervisor-owned text in Section 28.
- Generated source: never edit directly; refresh only through the supervisor lifecycle after formal-source incorporation.

## Score And Metadata Recommendation

| Document | Current | Recommended | Rationale |
| --- | ---: | ---: | --- |
| UID0002GH target | `86/92` | `94/96 very-strong` | Exact ABI, complete branch behavior, exact bytes/tables, vtable caller evidence, fields, source placement, and human-quality formal source |
| UID00002Z class | `90/93` | retain `90/93 very-strong` | Declaration/layout are already complete; this adds child behavior evidence without resolving unrelated class uncertainties |
| `Chatting` by-file | `89/93` | retain `89/93 very-strong` | Ownership/emission are already established; this fills one child formal block |

The target does not receive 100% because stripped local/method lexical names and whether the original source wrote an explicit empty case 5 are unrecoverable. Those uncertainties do not affect ABI, control flow, side effects, bytes, source placement, or compiler table regeneration.

Recommended metadata: classification `class method with compiler tail data`; current ordinary-document state `source-ready and incorporated at 94/96 through the exact seven-document callback`; remaining supervisor work is generated refresh/readback, manual coverage, Gate 2A/2B, report execution, and lifecycle archival; owner/emitter UID00002Z; no independent child emitter; no import; no split.

## Open Questions With Attempted Resolution

| Question | Investigation | Resolution |
| --- | --- | --- |
| Is key 5 a meaningful legacy case? | Decoded both tables and followed selector destinations | It reaches the shared default return; omit an invented explicit case |
| Is default returning an integer? | Compared the current incomplete `int __thiscall(int this, int, _DWORD *)` pretype with the virtual declaration, callers, vtable slot, and control flow | No; the source ABI is void and uses bare return |
| Is the text palette owned? | Traced GetTextPalette use and all exits | Borrowed global palette; restore state, do not release |
| Should bounds be restored after the style offset? | Traced both draws and function exit | No restoration occurs; preserve mutation |
| Are EPFTileContext and FrameDrawRecord the same type? | Checked exact sizes and API semantics | Layout-compatible at this call only; retain types and explicit cast |
| Should tables be emitted? | Checked xrefs, switch lowering, and source consumers | No; compiler-generated from the sparse switch |
| Is there an alternate Draw owner? | Checked class/file routes, vtable, siblings, generated output, and searches | No; UID00002Z is the direct class owner/emitter and UID0000I5 is the established file owner/emitter |
| Is a complete IDA class UDT required? | Checked current type state and proposed function type | No; incomplete pointer type is sufficient and safer |

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

Exact `by-memory/-coverage-report.md` replacement:

```text
        - [UID:0002GH][0x004836a0-0x004839c0.ColorStringChattingMessageDrawWithTables](by-memory/0x004836a0-0x004839c0.ColorStringChattingMessageDrawWithTables.md) 0x004836a0-0x004839c0 | class method with compiler tail data | ColorStringChattingMessage::Draw : reconstructable : 94% : very-strong : Source-ready virtual Draw with exact GrafPort/RectBounds ABI and 0x1c message layout; preserves current EPF text mode, repeated wrapped two-pass caller-bounds offset, outlined text, borrowed text-palette RGB save/mutate/install/draw/entry-restore/palette-restore ordering, legacy CHATBACK.EPD frame mapping 143/12/1 to 0/1/2, NP tiled background, invalid-key void return, exact 636-byte body, compiler jump/selector tables, one-byte tail alignment, vtable-only liveness, Chatting.cpp placement, blank child H because the class owns the declaration, and protected no-handwritten-table handling.
```

Exact `by-class/-coverage-report.md` replacement:

```text
- [UID:00002Z][ColorStringChattingMessage](by-class/ColorStringChattingMessage.md) : reconstructable : 90% : very-strong : Complete ChattingMessage abstract interface and ColorStringChattingMessage declaration with RTTI-proven LObject inheritance, exact virtual Clone/MeasureLines/Draw slots, 0x1c concrete layout, owned UTF-16 text and color/style fields, exact constructor/destructor/deep-clone/line-count children, source-ready current/legacy Draw with custom palette restoration and compiler-covered switch tables, ChattingPane owned-list and virtual paint consumer, and compiler deleting-destructor distinction.
```

Exact clause to append before the terminal period of the existing `by-file/-coverage-report.md` Chatting row:

```text
; ColorStringChattingMessage additionally has source-ready virtual Draw with exact current EPF outlined/two-pass/custom-RGB behavior, legacy CHATBACK.EPD frame selection and NP tiling, caller-rectangle mutation, palette restoration, compiler-covered switch tables, and no duplicate H declaration
```

Exact support manual-coverage dispositions:

- UID0004HQ DLPalette::MapColor current state: no UID0004HQ row exists in `by-memory/-coverage-report.md`. Replacement/insert after parent UID0001E4 and before UID0004HS:

```text
        - [UID:0004HQ][0x00542ac0-0x00542adc.DLPaletteMapColor](by-memory/0x00542ac0-0x00542adc.DLPaletteMapColor.md) 0x00542ac0-0x00542adc | DLPalette member method | DLPalette::MapColor : reconstructable : 90% : very-strong : Exact source-ready bounded palette-index getter; returns zero above 255 and otherwise m_mappedColors[colorIndex], emits exact CPP/H through UID00003Z into Palette.cpp/Palette.h, and preserves exact range, padding, 23 render-consumer xrefs, inferred lexical names, and no owner movement.
```

No-change disposition: retain UID0004HQ score `90/93`, exact range, reconstructable status, UID00003Z owner/emitter, and Palette.cpp/Palette.h route.

- UID0004HR DLPalette::SetColor current state: no UID0004HR row exists in `by-memory/-coverage-report.md`. Replacement/insert immediately after UID0004HQ:

```text
        - [UID:0004HR][0x00542ae0-0x00542b4a.DLPaletteSetColor](by-memory/0x00542ae0-0x00542b4a.DLPaletteSetColor.md) 0x00542ae0-0x00542b4a | DLPalette member method | DLPalette::SetColor : reconstructable : 89% : very-strong : Exact source-ready void mapped-color setter; rejects indexes above 255, normalizes each RGB component 1..7 to 8, packs red/high green/middle blue/low through Surface-owned g_pfnPackPixel, stores m_mappedColors[colorIndex], emits exact CPP/H through UID00003Z into Palette.cpp/Palette.h, and preserves exact range/padding and four callers.
```

No-change disposition: retain UID0004HR score `89/92`, exact range, reconstructable status, UID00003Z owner/emitter, and Palette.cpp/Palette.h route.

- UID00003Z DLPalette owner current exact row:

```text
    - [UID:00003Z][DLPalette](by-class/DLPalette.md)(DLPalette.md) : 92% : very-strong : DLPalette class with exact 0x22c layout, typed two-byte palette-range ownership, source-ready default/copy/destruction and load/application routes, fixed 32-byte header and 256-entry mapped-color table, and Palette.cpp/Palette.h emission.
```

Replacement:

```text
    - [UID:00003Z][DLPalette](by-class/DLPalette.md) : reconstructable : 92% : very-strong : DLPalette class with exact 0x22c layout, typed two-byte palette-range ownership, source-ready default/copy/destruction and load/application routes, fixed 32-byte header and 256-entry mapped-color table, exact source-ready MapColor/SetColor/SetPackedColor methods, and Palette.cpp/Palette.h child aggregation.
```

No-change disposition: retain UID00003Z score `92/94`, UID0000MA owner/emitter, exact `0x22c` layout, reconstructable status, and Palette.cpp/Palette.h route.

- UID00005V GrafPort owner current exact row:

```text
- [UID:00005V][GrafPort](by-class/GrafPort.md) : reconstructable : 88% : very-strong : Core graphics-port class with exact surface/clip/draw/text children, inherited UID000161 GrafPort::GetBounds over m_visibleBounds +0x44, draw enable/mode at +0x71/+0x70, and canonical callback color fields m_drawColor +0x74 and m_textBackFillColor +0x78; UID0002TG's Surface-owned RGB565 scaled-RLE-tint callback uses GrafPort only as its receiver dependency through m_drawEnabled, m_surfaceContext pixelData/rowStridePixels/bounds, and GetClipRect, without moving provider ownership into GrafPort; broad UI/map/render receivers reject historical BackPane or callback-owner pollution while the broad class formal remains blank to avoid a lossy partial shell.
```

Replacement:

```text
- [UID:00005V][GrafPort](by-class/GrafPort.md) : reconstructable : 88% : very-strong : Core graphics-port class with exact surface/clip/draw/text children, inherited UID000161 GrafPort::GetBounds over m_visibleBounds +0x44, draw enable/mode at +0x71/+0x70, public inline SetDrawMode and SetTextDrawMode one-byte state setters required by source consumers, and canonical callback color fields m_drawColor +0x74 and m_textBackFillColor +0x78; UID0002TG's Surface-owned RGB565 scaled-RLE-tint callback uses GrafPort only as its receiver dependency through m_drawEnabled, m_surfaceContext pixelData/rowStridePixels/bounds, and GetClipRect, without moving provider ownership into GrafPort; broad UI/map/render receivers reject historical BackPane or callback-owner pollution.
```

No-change disposition: retain UID00005V score `88/90`, UID0000JR owner/emitter, exact `0xa0` layout, reconstructable status, and the established GrafPort source route.

These are recommendations only. B010 did not edit any coverage report or tracker.

## Follow-Up Actions

1. Supervisor performs a fresh Gate 1 audit against this exact report artifact.
2. Supervisor performs an authorized generated refresh and physically rereads current Chatting, Palette, and GrafPort CPP/H output for C2GH-055 and C2GH-057 through C2GH-061.
3. Supervisor alone applies the exact manual coverage dispositions C2GH-038 through C2GH-040 and C2GH-051 through C2GH-054.
4. Supervisor completes Gate 2A by independently verifying all seven ordinary-document implementations and current generated authority claim by claim.
5. Supervisor completes Gate 2B against a fresh exact `DB`: pass public schema-1 runtime attestation, reproduce every I01/P01-P06 prestate, apply only the bounded accepted action, verify every post-readback, preserve protected entities, and back up/save under supervisor ownership.
6. Supervisor runs the report lifecycle execution only after Gate 2A and Gate 2B pass, then verifies the exact moved artifact, validator-owned status/history, archive path, and persisted audit.

No listed action is authorized by this report alone.

## Confidence

Overall recommendation: `94/96 very-strong`.

- ABI and class identity: very strong.
- Current branch behavior and side effects: very strong.
- Legacy branch and table mapping: very strong.
- Source owner/emitter and placement: very strong.
- Exact original lexical naming: limited but non-behavioral.
- Explicit original case-5 spelling: unknowable but behaviorally irrelevant.

## Validator Results

After the explicit callback, B010 ran exactly the seven allocated scoped validators while each destination was leased, then released every lease. No lifecycle command, generated refresh, report execution, coverage edit, or IDA mutation was run.

| Claim | Destination | Receipt | Physical generated readback |
| --- | --- | --- | --- |
| C2GH-055 | target | Command `000000023516`, timestamp `2026-08-14T11:55:12-04:00`, exit `0`, `ok:1`, generated refresh skipped; target completion/confidence and formal registry updated. | Blocked pending supervisor refresh: command-23511 Chatting.cpp still has the old UID0002GH empty marker and no Draw definition. |
| C2GH-056 | ColorStringChattingMessage owner | Command `000000023517`, timestamp `2026-08-14T11:56:10-04:00`, exit `0`, `ok:1`, generated refresh skipped. | Passed against newest existing snapshot: command-23511 Chatting.h contains the exact concrete virtual Draw declaration once, with the abstract pure declaration separate. |
| C2GH-057 | Chatting file owner | Command `000000023518`, timestamp `2026-08-14T11:56:52-04:00`, exit `0`, `ok:1`, generated refresh skipped. | Blocked pending supervisor refresh: Chatting.h declaration is exact once, but command-23511 Chatting.cpp has no Draw definition and retains the old marker. |
| C2GH-058 | MapColor child | Command `000000023519`, timestamp `2026-08-14T11:57:46-04:00`, exit `0`, `ok:1`, generated refresh skipped; CPP/H formal registry changed from blank to block. | Blocked pending supervisor refresh: command-23511 Palette.cpp/.h retain UID0004HQ's old marker and contain neither MapColor definition nor declaration. |
| C2GH-059 | SetColor child | Command `000000023524`, timestamp `2026-08-14T11:58:35-04:00`, exit `0`, `ok:1`, generated refresh skipped; CPP formal registry changed from blank to block. | Blocked pending supervisor refresh: command-23511 Palette.cpp/.h retain UID0004HR's old marker and contain neither SetColor definition nor declaration. |
| C2GH-060 | DLPalette owner | Command `000000023525`, timestamp `2026-08-14T11:59:32-04:00`, exit `0`, `ok:1`, generated refresh skipped. Six pre-existing missing-reference warnings name UID0003MU/UID0003MT and do not concern this callback. | Blocked pending supervisor refresh: command-23511 Palette CPP/H contain SetPackedColor once but not the newly registered MapColor/SetColor CPP/H. |
| C2GH-061 | GrafPort owner | Command `000000023526`, timestamp `2026-08-14T12:00:15-04:00`, exit `0`, `ok:1`, generated refresh skipped. Three pre-existing missing-reference warnings name UID0003XE and do not concern this callback. | Blocked pending supervisor refresh: command-23511 GrafPort.h contains neither inline setter; GrafPort.cpp remains unchanged/coherent at SHA256 `DD2E22EF390F8958B8F91F1FE00D546D237721CB16F7B210D56AE952336FDF79`. |

This is an honest partial generated-current result, not validator failure. The accepted commands deliberately disabled generated refresh. C2GH-055 and C2GH-057 through C2GH-061 remain unchecked with `blocked` verification until supervisor-authorized coherent refresh and readback; C2GH-056 is complete because its exact declaration was already present and physically reverified.

Research self-check requirements before return:

- exact 33 section headings;
- exact ledger/checklist claim count and eight-field parity;
- implementation Done cells checked only for ordinary claims that are physically complete; generated-current claims remain unchecked when their required refreshed output is absent;
- one terminal readiness marker;
- only C++ or inert text code fences;
- no executable PowerShell, Python, batch, shell, JavaScript, or C# material;
- stable SHA256 reread;
- no active B010 lease.

## Changed Files

The explicit callback changed exactly these ordinary documents plus this report:

- `by-memory/0x004836a0-0x004839c0.ColorStringChattingMessageDrawWithTables.md`
- `by-class/ColorStringChattingMessage.md`
- `by-file/Chatting.md`
- `by-memory/0x00542ac0-0x00542adc.DLPaletteMapColor.md`
- `by-memory/0x00542ae0-0x00542b4a.DLPaletteSetColor.md`
- `by-class/DLPalette.md`
- `by-class/GrafPort.md`
- `tools/leaser/Agents/Agent-B010/research/0002GH-ColorStringChattingMessageDrawWithTables-empty-emitter-source-quality.md`

No generated, tracker, manual coverage, audit, lifecycle, notes, companion, or IDA artifact was edited. The supervisor edited `Agent-B010/goal.md` to deliver the callback; B010 did not edit that file.

## Implementation Tracking Checklist

Research preparation:

- [x] Read the project B-agent workflow and current Agent-B010 goal.
- [x] Confirm the canonical IDA session and exact IDB.
- [x] Recheck the complete function ABI, body, frame, comments, bytes, and xrefs.
- [x] Decode current/legacy behavior, palette transaction, and compiler tables.
- [x] Recheck callers, vtable slot, fields, dependencies, owner, and emitter.
- [x] Produce exact human-quality CPP/H and support-owner recommendations.
- [x] Complete target-specific positive, negative, and inference reanalysis.
- [x] Receive supervisor Gate 1 acceptance.
- [x] Receive explicit implementation callback.
- [x] Incorporate and validate destination documents.

Claim checklist:

| Done | Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| [x] | C2GH-001 | 0002GH | UID0002GH route: Retain direct owner/emitter UID00002Z and class-to-file owner/emitter UID0000I5. Empty-emitter child does not gain a separate source file. | 99 | target, class, file, and generated ownership evidence; actor allocation: B010 ordinary target/support by-* implementation; Supervisor independent verification. | target Metadata / Ownership | incorporate | applied |
| [x] | C2GH-002 | 0002GH | UID0002GH function body: Record exact body identity and preserve bytes. Tables begin after the function. | 99 | `[0x004836a0,0x0048391c)`, 636 bytes, SHA256 `DF4DFC2018D31D28EEF3DAE2A168A8A813E75B440911EFAA9617EA10B9EC3DAA`; actor allocation: B010 ordinary by-* documentation; Supervisor Gate 2B IDA precheck/no-change readback and independent verification. | target IDA / Range | incorporate | applied |
| [x] | C2GH-003 | 0002GH | Draw ABI: Use `void __thiscall ColorStringChattingMessage::Draw(GrafPort *, RectBounds *)`. Current `int __thiscall(int this, int, _DWORD *)` pretype is incomplete. | 99 | vtable slot, class declaration, frame, virtual callers; actor allocation: B010 ordinary by-* documentation; Supervisor Gate 2B IDA precheck/no-change readback and independent verification. | target Formal / IDA | incorporate | applied |
| [x] | C2GH-004 | 0002GH | concrete layout: Record size `0x1c` and fields at `+00,+04,+08,+0c,+10,+14,+18`. No complete IDA UDT mutation. | 98 | constructor/class fields and target accesses; actor allocation: B010 ordinary by-* documentation; Supervisor Gate 2B IDA precheck/no-change readback and independent verification. | target Formal / class doc | incorporate | applied |
| [x] | C2GH-005 | 0002GH | current-mode entry: Preserve `g_useEpfAssets == true` and initialized otherwise-unused EPFTileContext. Generic nonzero test is not exact. | 99 | equality test and first call; actor allocation: B010 ordinary target/support by-* implementation; Supervisor independent verification. | target Formal CPP | incorporate | applied |
| [x] | C2GH-006 | 0002GH | current-mode setup: Set text draw mode 1 and foreground text color. Use GrafPort owner setter. | 98 | stores/calls before branch; actor allocation: B010 ordinary target/support by-* implementation; Supervisor independent verification. | target Formal CPP | incorporate | applied |
| [x] | C2GH-007 | 0002GH | style path: Draw, offset caller bounds `(1,0)`, reset mode/colors, and draw again. Bounds are not restored. | 99 | two draw blocks and RectBounds call; actor allocation: B010 ordinary target/support by-* implementation; Supervisor independent verification. | target Formal CPP | incorporate | applied |
| [x] | C2GH-008 | 0002GH | ordinary outlined path: Set background color and draw outlined text once. Applies when both override fields are zero. | 98 | zero-override branch; actor allocation: B010 ordinary target/support by-* implementation; Supervisor independent verification. | target Formal CPP | incorporate | applied |
| [x] | C2GH-009 | 0002GH | RGB override trigger: When either override is nonzero, rewrite both palette entries from packed RGB bytes. High/middle/low bytes map to R/G/B. | 98 | OR test and six component extracts; actor allocation: B010 ordinary target/support by-* implementation; Supervisor independent verification. | target Formal CPP | incorporate | applied |
| [x] | C2GH-010 | 0002GH | palette transaction: Save entries, set colors, save/install palette, draw, restore entries, restore palette. No palette release. | 99 | call order and borrowed pointer use; actor allocation: B010 ordinary target/support by-* implementation; Supervisor independent verification. | target Formal CPP | incorporate | applied |
| [x] | C2GH-011 | 0002GH | text lengths: Evaluate text length independently at each source draw call. Style path scans twice. | 98 | four independent inline scan loops; actor allocation: B010 ordinary target/support by-* implementation; Supervisor independent verification. | target Formal CPP | incorporate | applied |
| [x] | C2GH-012 | 0002GH | legacy frame mapping: Map `143->0`, `12->1`, `1->2`. Order may follow decompile without behavior change. | 99 | switch control flow and table decode; actor allocation: B010 ordinary target/support by-* implementation; Supervisor independent verification. | target Formal CPP | incorporate | applied |
| [x] | C2GH-013 | 0002GH | legacy default: Use bare default return for every other key. Do not return residual EAX. | 99 | void ABI and shared return block; actor allocation: B010 ordinary target/support by-* implementation; Supervisor independent verification. | target Formal CPP | incorporate | applied |
| [x] | C2GH-014 | 0002GH | legacy drawing: Initialize context, lookup `CHATBACK.EPD`, set draw mode 0, tile with `NP`, then draw text. Use explicit one-boundary record cast. | 98 | resource lookup and draw calls; actor allocation: B010 ordinary target/support by-* implementation; Supervisor independent verification. | target Formal CPP | incorporate | applied |
| [x] | C2GH-015 | 0002GH | jump table: Classify as compiler-emitted switch data and preserve unchanged. No handwritten table. | 99 | `[0x0048391c,0x00483930)` exact dwords and hash; actor allocation: B010 ordinary by-* documentation; Supervisor Gate 2B IDA precheck/no-change readback and independent verification. | target Range / IDA protection | incorporate | applied |
| [x] | C2GH-016 | 0002GH | selector table: Classify as compiler-emitted switch data and preserve unchanged. Key 5 shares default behavior. | 99 | `[0x00483930,0x004839bf)` exact selector values and hash; actor allocation: B010 ordinary by-* documentation; Supervisor Gate 2B IDA precheck/no-change readback and independent verification. | target Range / IDA protection | incorporate | applied |
| [x] | C2GH-017 | 0002GH | table source status: Emit no table declaration or definition. Compiler regenerates both tables. | 99 | switch lowering and no source consumer; actor allocation: B010 ordinary target/support by-* implementation; Supervisor independent verification. | target Formal CPP / H | incorporate | applied |
| [x] | C2GH-018 | 0002GH | tail alignment: Preserve one-byte alignment and exclude from source. Successor starts at `0x004839c0`. | 99 | `[0x004839bf,0x004839c0)` = `CC`; actor allocation: B010 ordinary by-* documentation; Supervisor Gate 2B IDA precheck/no-change readback and independent verification. | target Range / IDA protection | incorporate | applied |
| [x] | C2GH-019 | 0002GH | complete target pocket: Record exact complete range identity. Function, tables, and tail. | 99 | 800 bytes SHA256 `97E2EA981E07E0DB79783BC4528DB44B9E144E2C4828A71968A4D4F8B999A654`; actor allocation: B010 ordinary by-* documentation; Supervisor Gate 2B IDA precheck/no-change readback and independent verification. | target Range | incorporate | applied |
| [x] | C2GH-020 | 0002GH | boundaries: Preserve start/end; do not split, merge, or define functions. Current modeling is correct. | 99 | six-byte CC prepad and successor function; actor allocation: B010 ordinary by-* documentation; Supervisor Gate 2B IDA precheck/no-change readback and independent verification. | target Range | incorporate | applied |
| [x] | C2GH-021 | 0002GH | vtable slot: Record Draw as primary vtable slot `+0x14`. Cell bytes remain unchanged. | 99 | cell `0x00615280` points to target; six-slot vtable evidence; actor allocation: B010 ordinary by-* documentation; Supervisor Gate 2B IDA precheck/no-change readback and independent verification. | target Xrefs / Class | incorporate | applied |
| [x] | C2GH-022 | 0002GH | ChattingPane calls: Document both current-width and legacy-width paint consumers. Measure slot `+0x10` precedes Draw. | 98 | `0x0047fa4c` and `0x0047fb75` virtual calls; actor allocation: B010 ordinary target/support by-* implementation; Supervisor independent verification. | target Callers | incorporate | applied |
| [x] | C2GH-023 | 0002GH | virtual liveness: Treat vtable dispatch as live use, not dead code. No direct-call wrapper required. | 99 | zero direct code callers and one vtable data xref; actor allocation: B010 ordinary target/support by-* implementation; Supervisor independent verification. | target Callers / Negative evidence | incorporate | applied |
| [x] | C2GH-024 | 0002GH | callee inventory: Record all 14 semantic callees plus the security-cookie helper. Supports behavior and owner routing. | 98 | complete bounded call profile; actor allocation: B010 ordinary target/support by-* implementation; Supervisor independent verification. | target Dependencies | incorporate | applied |
| [x] | C2GH-025 | 0002GH | dependency ownership: Keep consumers as dependencies, not alternate emitters. No third-party import. | 97 | existing EPF/GrafPort/DLPalette/ResourceLayout owners; actor allocation: B010 ordinary target/support by-* implementation; Supervisor independent verification. | support docs | incorporate | applied |
| [x] | C2GH-026 | 0002GH | source placement: Place method in `Chatting.cpp` and declaration in class-owned `Chatting.h`. No new translation unit. | 99 | class and by-file routing; actor allocation: B010 ordinary target/support by-* implementation; Supervisor independent verification. | target/class/file Metadata | incorporate | applied |
| [x] | C2GH-027 | 0002GH | target CPP: Replace blank formal CPP with the recommendation in this report. Human-quality source, no decompiler temporaries. | 96 | complete behavior reconstruction; actor allocation: B010 ordinary target/support by-* implementation; Supervisor independent verification. | target Formal CPP | incorporate | applied |
| [x] | C2GH-028 | 0002GH | target H: Keep child formal H blank and state class ownership. Avoid duplicate declaration. | 99 | class document already owns declaration; actor allocation: B010 ordinary target/support by-* implementation; Supervisor independent verification. | target Formal H | incorporate | applied |
| [x] | C2GH-029 | 00002Z | UID00002Z class document: Preserve declaration/layout; add Draw behavior/source-ready evidence. UID00002Z remains target's direct owner/emitter. | 98 | complete declaration and layout; actor allocation: B010 ordinary target/support by-* implementation; Supervisor independent verification. | `by-class/ColorStringChattingMessage.md` | incorporate | applied |
| [x] | C2GH-030 | 0000I5 | UID0000I5 file document: Add target formal block and evidence; preserve all other source. Class-level owner/emitter remains UID0000I5. | 98 | existing Chatting aggregation; actor allocation: B010 ordinary target/support by-* implementation; Supervisor independent verification. | `by-file/Chatting.md` | incorporate | applied |
| [x] | C2GH-031 | 0004HQ | UID0004HQ DLPalette::MapColor: Add exact CPP and H declaration through its own route. Returns zero for index above 255. | 96 | exact child behavior and current blank formal source; actor allocation: B010 ordinary target/support by-* implementation; Supervisor independent verification. | MapColor child and UID00003Z DLPalette owner | incorporate | applied |
| [x] | C2GH-032 | 0004HR | UID0004HR DLPalette::SetColor: Add exact CPP and H declaration through its own route. Normalizes components 1..7 to 8. | 96 | exact child behavior and current weak type; actor allocation: B010 ordinary target/support by-* implementation; Supervisor independent verification. | SetColor child and UID00003Z DLPalette owner | incorporate | applied |
| [x] | C2GH-033 | 00005V | UID00005V GrafPort mode setters: Add public inline `SetDrawMode` and `SetTextDrawMode` setters. Exact single-byte stores. | 95 | direct protected stores in target; actor allocation: B010 ordinary target/support by-* implementation; Supervisor independent verification. | GrafPort owner H | incorporate | applied |
| [x] | C2GH-034 | 0002GH | record-type boundary: Keep EPFTileContext local and cast only at DrawTiledBackground call. Do not collapse global types. | 96 | both records size `0x28` but distinct semantics; actor allocation: B010 ordinary target/support by-* implementation; Supervisor independent verification. | target Formal CPP | incorporate | applied |
| [x] | C2GH-035 | 0002GH | target score: Raise target to `94/96 very-strong`. Residual uncertainty is lexical only. | 96 | exact ABI, behavior, bytes, tables, callers, placement; actor allocation: B010 ordinary target/support by-* implementation; Supervisor independent verification. | target Metadata / coverage | incorporate | applied |
| [x] | C2GH-036 | 00002Z | class score: Retain `90/93 very-strong`. Add evidence without score inflation. | 98 | declaration/layout already complete; actor allocation: B010 ordinary target/support by-* implementation; Supervisor independent verification. | class Metadata / coverage | incorporate | applied |
| [x] | C2GH-037 | 0000I5 | file score: Retain `89/93 very-strong`. Add target evidence without score inflation. | 98 | placement/emitter already strong; actor allocation: B010 ordinary target/support by-* implementation; Supervisor independent verification. | file Metadata / coverage | incorporate | applied |
| [ ] | C2GH-038 | 0002GH | by-memory coverage row: Replace row with exact text in Section 28. Supervisor-owned callback only. | 96 | current UID row and this report; actor allocation: Supervisor manual coverage implementation and independent verification. | `by-memory/-coverage-report.md` | incorporate | proposed |
| [ ] | C2GH-039 | 00002Z | by-class coverage row: Replace row with exact text in Section 28. Supervisor-owned callback only. | 96 | current UID00002Z row and this report; actor allocation: Supervisor manual coverage implementation and independent verification. | `by-class/-coverage-report.md` | incorporate | proposed |
| [ ] | C2GH-040 | 0000I5 | by-file coverage row: Append exact clause in Section 28. Preserve existing row text. | 96 | current Chatting row and this report; actor allocation: Supervisor manual coverage implementation and independent verification. | `by-file/-coverage-report.md` | incorporate | proposed |
| [ ] | C2GH-041 | 0002GH | I01 function identity: Apply only the bounded rename/type/comment delta after all prechecks. Runtime action is supervisor-owned. | 99 | exact prestate, collision, frame, body, comments; actor allocation: Supervisor Gate 2B IDA precheck/application/readback and independent verification. | IDA `0x004836a0` | incorporate | proposed |
| [ ] | C2GH-042 | 0002GH | I01 pure rename: Require current MCP rename with `pure:true`; prohibit ordinary rename effects. No `/vibe/` state or refresh side effects. | 99 | proposed-name collision result `Not found`; actor allocation: Supervisor Gate 2B IDA precheck/application/readback and independent verification. | IDA rename operation | incorporate | proposed |
| [ ] | C2GH-043 | 0002GH | P01 prepad: Read back byte-identical, otherwise stop without save. Protected no-change row. | 99 | six CC bytes and exact hash; actor allocation: Supervisor Gate 2B IDA precheck/application/readback and independent verification. | IDA `[0x0048369a,0x004836a0)` | already-present | proposed |
| [ ] | C2GH-044 | 0002GH | P02 jump table: Read back all state unchanged, otherwise stop without save. Protected no-change row. | 99 | exact item, comments, xref, bytes, hash; actor allocation: Supervisor Gate 2B IDA precheck/application/readback and independent verification. | IDA `[0x0048391c,0x00483930)` | already-present | proposed |
| [ ] | C2GH-045 | 0002GH | P03 selector table: Read back all state unchanged, otherwise stop without save. Protected no-change row. | 99 | exact item, comments, xref, bytes, hash; actor allocation: Supervisor Gate 2B IDA precheck/application/readback and independent verification. | IDA `[0x00483930,0x004839bf)` | already-present | proposed |
| [ ] | C2GH-046 | 0002GH | P04 tail byte: Read back all state unchanged, otherwise stop without save. Protected no-change row. | 99 | unnamed CC item with blank metadata and zero xrefs; actor allocation: Supervisor Gate 2B IDA precheck/application/readback and independent verification. | IDA `[0x004839bf,0x004839c0)` | already-present | proposed |
| [ ] | C2GH-047 | 0002GH | P05 vtable cell: Read back the complete cell identity unchanged, otherwise stop without save. No neighbor mutation. | 99 | data item `[0x00615280,0x00615284)`, blank name/type/comments, one outbound data xref, bytes/hash; actor allocation: Supervisor Gate 2B IDA precheck/application/readback and independent verification. | IDA vtable cell `[0x00615280,0x00615284)` | already-present | proposed |
| [x] | C2GH-048 | 0002GH | Callback implementation boundary: B010 changed exactly seven ordinary target/support by-* documents; generated source, manual coverage, tracker, lifecycle, audit, and IDA remained supervisor-owned and were not edited or mutated by B010. | 99 | post-callback changed-file hashes and validator command IDs `000000023516` through `000000023526`; generated command `000000023511` remained stale by the explicit no-refresh allocation; actor allocation: B010 ordinary implementation/report maintenance; Supervisor generated refresh, coverage, Gate 2, audit, and lifecycle. | callback boundary / Changed Files / Validator Results | incorporate | applied |
| [ ] | C2GH-049 | 0002GH | IDA type prerequisite: Preserve the current opaque `ColorStringChattingMessage` local type exactly; no `declare_type`, UDT completion, or other prerequisite mutation. A pointer-qualified function type is sufficient. | 99 | literal `type_inspect`: exists true, declaration `ColorStringChattingMessage`, size `18446744073709551615`, is_func/is_ptr/is_enum/is_udt false, members null, member_count 0; actor allocation: Supervisor Gate 2B IDA precheck/no-change readback and independent verification. | IDA local type prerequisite | already-present | proposed |
| [ ] | C2GH-050 | 0002GH | P06 successor function: Read back both code items, function identity, metadata, xrefs, bytes, and hash unchanged, otherwise stop without save. | 99 | `sub_4839C0 [0x004839c0,0x004839cb)`, two code items, exact comments/xrefs/bytes/hash; actor allocation: Supervisor Gate 2B IDA precheck/application/readback and independent verification. | IDA successor `[0x004839c0,0x004839cb)` | already-present | proposed |
| [ ] | C2GH-051 | 0004HQ | UID0004HQ manual coverage: Insert the exact current-absent DLPalette::MapColor row from Section 28 without changing its 90/93 score, UID00003Z route, range, or reconstructable state. | 98 | literal current absence and exact insertion text in Section 28; actor allocation: Supervisor manual coverage implementation and independent verification. | `by-memory/-coverage-report.md` | incorporate | proposed |
| [ ] | C2GH-052 | 0004HR | UID0004HR manual coverage: Insert the exact current-absent DLPalette::SetColor row from Section 28 without changing its 89/92 score, UID00003Z route, range, or reconstructable state. | 98 | literal current absence and exact insertion text in Section 28; actor allocation: Supervisor manual coverage implementation and independent verification. | `by-memory/-coverage-report.md` | incorporate | proposed |
| [ ] | C2GH-053 | 00003Z | DLPalette owner manual coverage: Replace the exact current UID00003Z row with the Section 28 text adding MapColor/SetColor/SetPackedColor and child aggregation; retain score 92/94 and UID0000MA ownership. | 98 | literal current row, replacement row, and no-change disposition in Section 28; actor allocation: Supervisor manual coverage implementation and independent verification. | `by-class/-coverage-report.md` | incorporate | proposed |
| [ ] | C2GH-054 | 00005V | GrafPort owner manual coverage: Replace the exact current UID00005V row with the Section 28 text adding the two public inline mode setters; retain score 88/90, 0xa0 layout, and UID0000JR ownership. | 98 | literal current row, replacement row, and no-change disposition in Section 28; actor allocation: Supervisor manual coverage implementation and independent verification. | `by-class/-coverage-report.md` | incorporate | proposed |
| [ ] | C2GH-055 | 0002GH | Scoped target page validation after incorporation: validate while leased with generated refresh skipped, then verify newest Chatting.cpp contains the full Draw body and no empty marker. | 99 | literal command: `python .\tools\validator.py --mode file --file by-memory/0x004836a0-0x004839c0.ColorStringChattingMessageDrawWithTables.md --apply --no-generated-refresh --queue-timeout 240`; expect exit 0, ok:1, generated refresh skipped; actor allocation: B010 ordinary by-* implementation/validation; Supervisor independent verification. | target page validator / generated-current readback | incorporate | blocked |
| [x] | C2GH-056 | 00002Z | Scoped ColorStringChattingMessage owner validation after incorporation: validate while leased with generated refresh skipped, then verify newest Chatting.h retains the exact class declaration and virtual Draw. | 99 | literal command: `python .\tools\validator.py --mode file --file by-class/ColorStringChattingMessage.md --apply --no-generated-refresh --queue-timeout 240`; expect exit 0, ok:1, generated refresh skipped; actor allocation: B010 ordinary by-* implementation/validation; Supervisor independent verification. | ColorStringChattingMessage owner validator / generated-current readback | incorporate | applied |
| [ ] | C2GH-057 | 0000I5 | Scoped Chatting file owner validation after incorporation: validate while leased with generated refresh skipped, then verify newest Chatting.cpp/Chatting.h emit the Draw definition/declaration exactly once. | 99 | literal command: `python .\tools\validator.py --mode file --file by-file/Chatting.md --apply --no-generated-refresh --queue-timeout 240`; expect exit 0, ok:1, generated refresh skipped; actor allocation: B010 ordinary by-* implementation/validation; Supervisor independent verification. | Chatting file owner validator / generated-current readback | incorporate | blocked |
| [ ] | C2GH-058 | 0004HQ | Scoped MapColor child validation after incorporation: validate while leased with generated refresh skipped, then verify newest Palette.cpp/Palette.h emit MapColor exactly once through UID00003Z. | 99 | literal command: `python .\tools\validator.py --mode file --file by-memory/0x00542ac0-0x00542adc.DLPaletteMapColor.md --apply --no-generated-refresh --queue-timeout 240`; expect exit 0, ok:1, generated refresh skipped; actor allocation: B010 ordinary by-* implementation/validation; Supervisor independent verification. | MapColor child validator / generated-current readback | incorporate | blocked |
| [ ] | C2GH-059 | 0004HR | Scoped SetColor child validation after incorporation: validate while leased with generated refresh skipped, then verify newest Palette.cpp/Palette.h emit SetColor exactly once through UID00003Z. | 99 | literal command: `python .\tools\validator.py --mode file --file by-memory/0x00542ae0-0x00542b4a.DLPaletteSetColor.md --apply --no-generated-refresh --queue-timeout 240`; expect exit 0, ok:1, generated refresh skipped; actor allocation: B010 ordinary by-* implementation/validation; Supervisor independent verification. | SetColor child validator / generated-current readback | incorporate | blocked |
| [ ] | C2GH-060 | 00003Z | Scoped DLPalette owner validation after incorporation: validate while leased with generated refresh skipped, then verify newest Palette.cpp/Palette.h contain all three coherent palette methods and declarations exactly once. | 99 | literal command: `python .\tools\validator.py --mode file --file by-class/DLPalette.md --apply --no-generated-refresh --queue-timeout 240`; expect exit 0, ok:1, generated refresh skipped; actor allocation: B010 ordinary by-* implementation/validation; Supervisor independent verification. | DLPalette owner validator / generated-current readback | incorporate | blocked |
| [ ] | C2GH-061 | 00005V | Scoped GrafPort owner validation after incorporation: validate while leased with generated refresh skipped, then verify newest GrafPort header emits both inline mode setters exactly once and generated CPP remains coherent. | 99 | literal command: `python .\tools\validator.py --mode file --file by-class/GrafPort.md --apply --no-generated-refresh --queue-timeout 240`; expect exit 0, ok:1, generated refresh skipped; actor allocation: B010 ordinary by-* implementation/validation; Supervisor independent verification. | GrafPort owner validator / generated-current readback | incorporate | blocked |

Implementation allocation:

- [x] B010 incorporates the seven ordinary target/support by-* destinations only after explicit callback.
- [x] B010 runs each scoped validator while its destination lease is active with generated refresh skipped.
- [x] B010 releases each ordinary destination lease immediately after its edit/validation.
- [ ] Supervisor applies the seven exact manual coverage dispositions.
- [ ] Supervisor performs the bounded I01 and P01-P06 Gate 2B transaction/readback.
- [ ] Supervisor independently verifies ordinary documents and generated-current authority.
- [ ] Supervisor alone controls generated refresh authorization, lifecycle, report execution, and move/archive.
- [x] Recheck all 61 claim rows after incorporation.
- [ ] Complete final archived-artifact audit after supervisor move.

Checklist claim count: `61`. Done allocation for claim rows: `39` checked and `22` unchecked. Full report checkbox allocation: `53` checked and `27` unchecked.
READY_FOR_SUPERVISOR_EXECUTE

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B010","command_id":"000000023540","destination_path":"executed-b-agent-research/B010/0002GH-ColorStringChattingMessageDrawWithTables-empty-emitter-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B010/research/0002GH-ColorStringChattingMessageDrawWithTables-empty-emitter-source-quality.md","timestamp":"2026-08-14T13:52:28-04:00","uid":"0002GH"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
