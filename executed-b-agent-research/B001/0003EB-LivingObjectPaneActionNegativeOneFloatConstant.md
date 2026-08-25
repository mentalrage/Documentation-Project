** TARGET-REPORT-UID:0003EB **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003EB **
# 0003EB LivingObjectPaneActionNegativeOneFloatConstant Ownership Research

Revision: B001-0003EB finalized ownership/split repair, 2026-06-12

## Finalized Report / Current Recommendation

- Target UID/path: [UID:0003EB] `by-memory/0x00630c24-0x00630c28.LivingObjectPaneActionNegativeOneFloatConstant.md`
- Final recommendation: assign [UID:0003EB] to existing source-file parent [UID:0000KU] `LivingObjectPane` / `NexusTK/map/LivingObjectPane.cpp`.
- Classification: reconstructable source-declared/generated scalar constant, `88/92`, `AUTOGEN_PARENT_UID:0000KU`.
- Repair applied: created exact child pages for the formerly broad raw-helper blocker:
  - [UID:0003H4] `by-memory/0x005acae0-0x005acb1f.LivingObjectPaneSendDirectionPacketRawHelper.md`, `85/86`, parent [UID:00007B] `LivingObjectPane`.
  - [UID:0003H5] `by-memory/0x005acb20-0x005acc23.LivingObjectPaneAutoFaceDirectionPacketRawHelper.md`, `86/88`, parent [UID:00007B] `LivingObjectPane`.
- Why assignment is justified: all four direct refs to `0x00630c24` now sit in `LivingObjectPane` action/facing packet code. The modeled refs are in `sub_5ACC30`; the two previous raw refs are specifically inside [UID:0003H5], not an undifferentiated raw `0x005ac9a0` region.
- Source family scope: do not create a new `FloatConstants.cpp`, `UserStatusMenu` file, or runtime/shared-float owner. The existing `LivingObjectPane.cpp` family already contains local-player movement/action packet helpers, retained raw action-tail helpers, `sub_5ACC30`, `0x005a58c0` action gating, and file-level orphan/static support such as [UID:00030B] `g_lastFunctionKeyTick`.
- Confidence: `92/100` for `LivingObjectPane.cpp` source-family ownership, `98/100` for bytes/value/range, `94/100` for xref inventory, `88/100` for exact raw-helper source reconstruction. Confidence stays below final-source quality because IDA has no entry xrefs or recovered source names for the raw helpers.
- Coverage-report handling: `by-memory/-coverage-report.md` was not edited. Exact supervisor row edits are listed in the "Required Coverage-Report Edits" section.
- Validator: focused file-mode validator runs with `--apply` returned `ok: 1` for [UID:0003H4], [UID:0003H5], [UID:0003EB], [UID:0002YY], [UID:0001KM], and [UID:0000VN] `-ignored.md`.

## Supporting Research

## Target

- UID: `0003EB`
- Path: `E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x00630c24-0x00630c28.LivingObjectPaneActionNegativeOneFloatConstant.md`
- Prior status: `86/91`, reconstructable, parent blank.
- Supervisor reason for B research: prior A004 work showed four direct refs, but two refs were in raw prologue-shaped code with no IDA function object or entry xrefs.

## Evidence Standards Used

- IDA MCP is treated as ground truth for bytes, xrefs, function boundaries, callee/caller facts, and negative entry-xref checks.
- Existing documentation is treated as hypothesis until corroborated by IDA or by stable cross-document consistency.
- A scalar literal's direct source parent need not be a class static member. If the literal appears as an inline threshold inside source methods, the file parent is often more accurate than the class page.
- Physical `.rdata` adjacency is not ownership proof. The mixed lead-in page [UID:0002YY] remains parentless even though one exact child now routes to `LivingObjectPane.cpp`.

## IDA MCP Facts

Live IDA MCP session: `b001_nexustk`, `NexusTK.exe`, 2026-06-12.

Exact scalar:

| Address | Bytes | Meaning |
| --- | --- | --- |
| `0x00630c24-0x00630c28` | `00 00 80 bf` | IEEE-754 `-1.0f`, IDA name `dword_630C24` |

`make_signature_for_range 0x00630c24-0x00630c28` returns `00 00 80 BF` and marks it non-unique. Ownership therefore depends on xrefs and context, not the byte pattern alone.

Direct xrefs to `0x00630c24`:

| Ref | Current context | B001 interpretation |
| --- | --- | --- |
| `0x005acbbd` | no IDA function; inside [UID:0003H5] `0x005acb20-0x005acc23` | raw LivingObjectPane auto-face slope threshold |
| `0x005acbdc` | no IDA function; inside [UID:0003H5] `0x005acb20-0x005acc23` | second raw LivingObjectPane threshold branch |
| `0x005accf9` | IDA function `sub_5ACC30` | modeled LivingObjectPane action/auto-face threshold |
| `0x005acd18` | IDA function `sub_5ACC30` | second modeled LivingObjectPane threshold branch |

Targeted byte search:

- `find_bytes F3 0F 10 05 24 0C 63 00`: exactly four matches, the four refs above.
- `find_bytes 0F 2F 0D 24 0C 63 00`: zero matches.
- `find_bytes 0F 2F 05 24 0C 63 00`: zero matches.

Function/boundary checks:

- `lookup_funcs 0x005acb20`: not a function.
- `xrefs_to 0x005acb20`: zero entry xrefs.
- `lookup_funcs 0x005acc30`: `sub_5ACC30`, size `0x155`, range `0x005acc30-0x005acd85`.
- `xrefs_to 0x005acc30`: one code xref at `0x005a5956` in `sub_5A58C0`.
- `xrefs_to 0x005a58c0`: callers at `0x00509092` in `sub_509030` and `0x005a5f87` in `sub_5A5BD0`.
- `get_bytes 0x005acc20 size 32`: `0x005acc23-0x005acc30` is thirteen `0xcc` bytes before `sub_5ACC30`.

Positive threshold contrast:

- `xrefs_to 0x006104b4` (`1.0f`) reports 62 refs overall.
- Relevant action-tail positive-threshold refs are `0x005acbb0`, `0x005acbcf`, `0x005accec`, and `0x005acd0b`.
- This contrast rejects a generic shared-float owner for `0x00630c24`: the `-1.0f` scalar has exactly four refs, all in the LivingObjectPane action/facing pair.

## Raw Helper Split Evidence

### [UID:0003H4] `0x005acae0-0x005acb1f`

This raw helper sends opcode `0x11` with a caller-supplied direction byte:

- prologue `push ebp; mov ebp, esp; sub esp, 0x10`;
- stack-cookie setup;
- reads the direction byte from `[ebp+8]`;
- loads `dword_67A7EC`;
- builds local bytes `{0x11, direction, 0}`;
- calls `sub_574BB0` with length `2`;
- returns with `retn 4` at `0x005acb1c`;
- one byte of `0xcc` alignment follows at `0x005acb1f-0x005acb20`.

There are no ordinary entry xrefs. The helper is still source-shaped NexusTK packet code and is adjacent to the auto-face helper. It is documented as retained/unreferenced raw `LivingObjectPane` method-shaped code, not final C++.

### [UID:0003H5] `0x005acb20-0x005acc23`

This raw helper owns the previously unresolved [UID:0003EB] xrefs:

- no current IDA function object at `0x005acb20`;
- zero entry xrefs to `0x005acb20`;
- saves `ecx` as `esi`, treating the receiver as the `LivingObjectPane` instance;
- resolves target object through `dword_67A764` and `dword_69BF28`;
- checks `byte [esi+0x13eb3c] == 1`;
- calls `sub_5374D0` for target coordinates;
- compares target coordinates against `this + 0x100` and `this + 0x104`;
- computes a slope;
- compares against `0x006104b4` (`1.0f`) and [UID:0003EB] `0x00630c24` (`-1.0f`);
- compares derived facing with `[esi+0x1c5]`;
- sends opcode `0x11` through `sub_574BB0` only when facing changes;
- returns at `0x005acc22`;
- thirteen bytes of `0xcc` alignment follow at `0x005acc23-0x005acc30`.

This body mirrors the auto-face section of `sub_5ACC30`, so it resolves the prior raw-helper ownership blocker without requiring IDA to define a function object.

## Modeled Helper Evidence

`analyze_function 0x005acc30` shows `sub_5ACC30` is a `thiscall` action sender:

- sets action opcode `0x13`;
- checks `this + 0x13eb3c`;
- resolves a selected/target object through `dword_67A764` and `dword_69BF28`;
- calls `sub_5374D0` for target position;
- reads local actor coordinates at `this + 0x100` and `this + 0x104`;
- computes target-facing slope;
- compares against `1.0f` and [UID:0003EB] `-1.0f`;
- sends opcode `0x11` through `sub_574BB0` when facing changes;
- then sends the action opcode `0x13` packet through `sub_574BB0`.

`analyze_function 0x005a58c0` shows this action sender is reached from the local-player action gate, updates action timing state, and is part of the documented [UID:0001KM] `LivingObjectPaneLocalPlayerExtensions` aggregate.

## Documentation Evidence

- [UID:0001KM] `LivingObjectPaneLocalPlayerExtensions` already owns the `0x005a2de0-0x005ad440` local-player movement/command/server-packet extension surface and lists `sub_5ACC30` as `SendActionPacketWithAutoFace`.
- [UID:0000KU] `LivingObjectPane` / `NexusTK/map/LivingObjectPane.cpp` is the source-file owner for this local-player movement/action helper family.
- [UID:00007B] `LivingObjectPane` class is the right direct parent for raw method-shaped helpers [UID:0003H4] and [UID:0003H5].
- [UID:0002YY] `UserStatusMenuMixedLeadInData` is a mixed `.rdata` lead-in and remains parentless. It contains the `Invalid name` literal, [UID:0003EB], and a `UserStatusPane` RTTI locator, so the aggregate cannot be assigned to a single source.
- [UID:00030B] `g_lastFunctionKeyTick` is a precedent for assigning file-level orphan/local helper support to [UID:0000KU] when the evidence points to `LivingObjectPane.cpp` but not to a class static data member.

## Ranked Ownership Analysis

### 1. [UID:0000KU] `LivingObjectPane.cpp` - accepted for [UID:0003EB]

Evidence for:

- All four direct scalar refs are now accounted for in LivingObjectPane action/facing packet code.
- The raw and modeled helpers share the same object fields, target lookup helpers, slope-to-facing logic, and `sub_574BB0` packet-send path.
- The raw helper pages attach to [UID:00007B] class ownership; the scalar itself is better modeled as file-level compiler-pooled/source-generated literal support.
- Existing `LivingObjectPane.cpp` scope already covers local-player packet helpers and file-level orphan state.

Evidence against:

- No original source spelling or symbol survives for the scalar.
- The constant is physically located inside a mixed status/menu `.rdata` neighborhood, but that is link-order adjacency, not ownership.

Decision: accepted. Set [UID:0003EB] parent to [UID:0000KU].

Confidence: `92/100`.

### 2. [UID:00007B] `LivingObjectPane` class - accepted for helper pages, rejected as scalar direct parent

Evidence for:

- [UID:0003H4] and [UID:0003H5] are method-shaped thiscall helpers and use LivingObjectPane fields/packet behavior.
- The class page is a suitable direct parent for the raw executable child pages.

Evidence against:

- [UID:0003EB] is a `.rdata` scalar literal, not a proven class static member.
- The safest source reconstruction is likely an inline numeric threshold inside methods compiled into file-level scalar storage.

Decision: use [UID:00007B] for [UID:0003H4] and [UID:0003H5], but keep [UID:0003EB] on [UID:0000KU].

Confidence: `88/100` for the helper pages, `70/100` for the scalar as class-static data.

### 3. [UID:0002YY] / UserStatusMenu or UserStatusPane - rejected

Evidence for:

- [UID:0003EB] is physically adjacent to `UserStatus` and status/menu `.rdata` items.

Evidence against:

- Direct xrefs do not route to UserStatusPane, MenuVarietyPanes, or block-list UI code.
- [UID:0002YY] is explicitly a mixed non-emitting index with children that route to different owners.
- The neighboring RTTI pointer and `Invalid name` string have unrelated owners.

Decision: reject as direct owner.

Confidence: `95/100` rejection.

### 4. [UID:0000P1] `UserPane` - rejected

Evidence for:

- The executable addresses sit inside the broad `0x005a2530-0x005b8395` UserPane physical neighborhood.

Evidence against:

- The concrete action-tail helper body uses LivingObjectPane fields and action/facing packets.
- Existing documentation separates LivingObjectPane local-player movement/action helpers from UserPane dispatch code.
- `sub_5ACC30` and [UID:0003H5] are semantically action/facing helpers, not UserPane UI methods.

Decision: reject as direct owner.

Confidence: `90/100` rejection.

### 5. Runtime/shared-float owner - rejected

Evidence for:

- `-1.0f` bytes are non-unique.

Evidence against:

- Exact address `0x00630c24` has only four refs, all LivingObjectPane action/facing refs.
- The broad shared `1.0f` constant at `0x006104b4` has 62 refs and a very different distribution.

Decision: reject shared/runtime constant ownership.

Confidence: `92/100` rejection.

## Repairs Applied

By-memory pages edited or created:

- Created [UID:0003H4] `by-memory/0x005acae0-0x005acb1f.LivingObjectPaneSendDirectionPacketRawHelper.md`, `85/86`, parent [UID:00007B].
- Created [UID:0003H5] `by-memory/0x005acb20-0x005acc23.LivingObjectPaneAutoFaceDirectionPacketRawHelper.md`, `86/88`, parent [UID:00007B].
- Updated [UID:0003EB] to `88/92`, parent [UID:0000KU].
- Updated [UID:0002YY] to record that [UID:0003EB] now routes to [UID:0000KU] while the mixed lead-in remains parentless.
- Updated [UID:0001KM] to list the exact raw action-tail split pages and preserve the broader `0x005ac7e0` / `0x005ac9a0` projected-start caveat.
- Updated [UID:0000VN] `-ignored.md` with padding spans `0x005acb1f-0x005acb20` and `0x005acc23-0x005acc30`.

Validator side effects observed:

- `tools/validator.ini` updated registry/reference metadata.
- `project-level/-auto-completion-stats.md` updated projected completion stats.
- `auto-generated/-ag-memory-coverage.md` shows [UID:0003H4], [UID:0003H5], and [UID:0003EB] assigned.
- Manual `by-memory/-coverage-report.md` remains untouched and still needs supervisor row updates below.

## Disconfirming Evidence Summary

- No IDA function object or entry xrefs exist at `0x005acb20`, so [UID:0003H5] should not be treated as a fully recovered named source method. This does not block ownership because the body itself is exact, source-shaped, and semantically matches `sub_5ACC30`.
- The broader projected `0x005ac9a0` region contains multiple raw function-shaped bodies; using that broad projection as the owner was too imprecise. Splitting [UID:0003H5] is the reason [UID:0003EB] can now be assigned safely.
- Physical adjacency to `UserStatusPane` `.rdata` is contradicted by the xref inventory: no direct xref to [UID:0003EB] enters `UserStatusPane`, `MenuVarietyPanes`, or block-list validation code.
- A class-static assignment to [UID:00007B] is weaker than file-parent assignment because IDA shows a scalar literal pool entry, not an authored class field.
- Runtime/shared-float ownership is contradicted by the exact xref distribution. The shared `1.0f` at `0x006104b4` has 62 refs, while [UID:0003EB] has only four refs and all four are in the LivingObjectPane action/facing pair.

## Validation

Focused validators were run after documentation edits:

- `python source-3/project-documentation/tools/validator.py --mode file --file source-3/project-documentation/by-memory/0x005acae0-0x005acb1f.LivingObjectPaneSendDirectionPacketRawHelper.md --apply` -> `ok: 1`
- `python source-3/project-documentation/tools/validator.py --mode file --file source-3/project-documentation/by-memory/0x005acb20-0x005acc23.LivingObjectPaneAutoFaceDirectionPacketRawHelper.md --apply` -> `ok: 1`
- `python source-3/project-documentation/tools/validator.py --mode file --file source-3/project-documentation/by-memory/0x00630c24-0x00630c28.LivingObjectPaneActionNegativeOneFloatConstant.md --apply` -> `ok: 1`
- `python source-3/project-documentation/tools/validator.py --mode file --file source-3/project-documentation/by-memory/0x00630c06-0x00630c2c.UserStatusMenuMixedLeadInData.md --apply` -> `ok: 1`
- `python source-3/project-documentation/tools/validator.py --mode file --file source-3/project-documentation/by-memory/0x005a2de0-0x005ad440.LivingObjectPaneLocalPlayerExtensions.md --apply` -> `ok: 1`
- `python source-3/project-documentation/tools/validator.py --mode file --file source-3/project-documentation/by-memory/-ignored.md --apply` -> `ok: 1`

Validator-owned side effects updated `tools/validator.ini`, `project-level/-auto-completion-stats.md`, and generated coverage reference files. `by-memory/-coverage-report.md` was not manually edited.

## Required Coverage-Report Edits

Do not edit `by-memory/-coverage-report.md` manually from this report. Supervisor should apply these exact row edits.

### Replace existing [UID:0001KM] row

Existing row context starts at the line:

```text
    - [UID:0001KM][0x005a2de0-0x005ad440.LivingObjectPaneLocalPlayerExtensions](by-memory/0x005a2de0-0x005ad440.LivingObjectPaneLocalPlayerExtensions.md) 0x005a2de0-0x005ad440 | class aggregate | LivingObjectPaneLocalPlayerExtensions : reconstructable : 82% : strong : Local-player movement/command/server-packet extension aggregate with current IDA start/size map, timer/macro evidence, projected-start caveats, and UserPane/say-input exclusions documented.
```

Replace with:

```text
    - [UID:0001KM][0x005a2de0-0x005ad440.LivingObjectPaneLocalPlayerExtensions](by-memory/0x005a2de0-0x005ad440.LivingObjectPaneLocalPlayerExtensions.md) 0x005a2de0-0x005ad440 | class aggregate | LivingObjectPaneLocalPlayerExtensions : reconstructable : 82% : strong : Local-player movement/command/server-packet extension aggregate with current IDA start/size map, timer/macro evidence, exact raw action-tail helper splits, projected-start caveats, and UserPane/say-input exclusions documented.
```

### Insert child rows under [UID:0001KM]

Insert after the existing [UID:0001KN] child row under [UID:0001KM]:

```text
        - [UID:0003H4][0x005acae0-0x005acb1f.LivingObjectPaneSendDirectionPacketRawHelper](by-memory/0x005acae0-0x005acb1f.LivingObjectPaneSendDirectionPacketRawHelper.md) 0x005acae0-0x005acb1f | raw-method | LivingObjectPaneSendDirectionPacketRawHelper : reconstructable : 85% : strong : Retained IDA-unmodeled LivingObjectPane direction packet helper; sends opcode 0x11 with caller-supplied direction byte through sub_574BB0, has no entry xrefs, and is assigned to [UID:00007B][LivingObjectPane](by-class/LivingObjectPane.md) as raw method-shaped source code.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x005acb1f-0x005acb20 | padding | LivingObjectPane direction helper to auto-face helper alignment : ignored : 100% : strong : 2026-06-12 B001 byte/disassembly audit shows one `0xcc` byte between [UID:0003H4][0x005acae0-0x005acb1f.LivingObjectPaneSendDirectionPacketRawHelper](by-memory/0x005acae0-0x005acb1f.LivingObjectPaneSendDirectionPacketRawHelper.md) and [UID:0003H5][0x005acb20-0x005acc23.LivingObjectPaneAutoFaceDirectionPacketRawHelper](by-memory/0x005acb20-0x005acc23.LivingObjectPaneAutoFaceDirectionPacketRawHelper.md).
        - [UID:0003H5][0x005acb20-0x005acc23.LivingObjectPaneAutoFaceDirectionPacketRawHelper](by-memory/0x005acb20-0x005acc23.LivingObjectPaneAutoFaceDirectionPacketRawHelper.md) 0x005acb20-0x005acc23 | raw-method | LivingObjectPaneAutoFaceDirectionPacketRawHelper : reconstructable : 86% : strong : Retained IDA-unmodeled LivingObjectPane auto-face direction helper; exact raw owner of [UID:0003EB][0x00630c24-0x00630c28.LivingObjectPaneActionNegativeOneFloatConstant](by-memory/0x00630c24-0x00630c28.LivingObjectPaneActionNegativeOneFloatConstant.md) refs at 0x005acbbd and 0x005acbdc, mirrors sub_5ACC30 slope/facing logic, and sends opcode 0x11 only when derived facing changes.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x005acc23-0x005acc30 | padding | LivingObjectPane auto-face helper to SendActionPacketWithAutoFace alignment : ignored : 100% : strong : 2026-06-12 B001 byte/disassembly audit shows thirteen `0xcc` bytes before confirmed sub_5ACC30 at 0x005acc30.
```

### Replace [UID:0002YY] row

Existing row context starts:

```text
        - [UID:0002YY][0x00630c06-0x00630c2c.UserStatusMenuMixedLeadInData](by-memory/0x00630c06-0x00630c2c.UserStatusMenuMixedLeadInData.md) 0x00630c06-0x00630c2c | mixed lead-in rdata index | UserStatusMenuMixedLeadInData : not_reconstructable : 85% : strong : Batch 228 renames/reclassifies the former leading-literal child as a non-emitting mixed lead-in index after live IDA proves it contains two zero bytes, exact `Invalid name` string child, referenced `dword_630C24` `-1.0f` child, and a `UserStatusPane` RTTI locator pointer before the `0x00630c2c` vtable.
```

Replace with:

```text
        - [UID:0002YY][0x00630c06-0x00630c2c.UserStatusMenuMixedLeadInData](by-memory/0x00630c06-0x00630c2c.UserStatusMenuMixedLeadInData.md) 0x00630c06-0x00630c2c | mixed lead-in rdata index | UserStatusMenuMixedLeadInData : not_reconstructable : 85% : strong : Non-emitting mixed lead-in index after live IDA proves it contains two zero bytes, exact `Invalid name` string child, referenced [UID:0003EB][0x00630c24-0x00630c28.LivingObjectPaneActionNegativeOneFloatConstant](by-memory/0x00630c24-0x00630c28.LivingObjectPaneActionNegativeOneFloatConstant.md) now assigned to [UID:0000KU][LivingObjectPane](by-file/LivingObjectPane.md), and a `UserStatusPane` RTTI locator pointer before the `0x00630c2c` vtable.
```

### Replace [UID:0003EB] row

Existing row context starts:

```text
            - [UID:0003EB][0x00630c24-0x00630c28.LivingObjectPaneActionNegativeOneFloatConstant](by-memory/0x00630c24-0x00630c28.LivingObjectPaneActionNegativeOneFloatConstant.md) 0x00630c24-0x00630c28 | float-constant | LivingObjectPaneActionNegativeOneFloatConstant : reconstructable : 86% : strong : Exact 4-byte IEEE-754 -1.0f scalar constant (bytes 00 00 80 bf / 0xbf800000); A004 Batch296 live IDA confirms exactly four movss refs, with 0x005accf9 and 0x005acd18 inside sub_5ACC30 and 0x005acbbd and 0x005acbdc in a prologue-shaped raw helper lacking an IDA function and entry xrefs; sub_5ACC30 is called from 0x005a58c0, derives a facing/action byte using 1.0f and -1.0f thresholds, and sends direction/action packets through sub_574BB0; parent remains blank until the raw helper is split or its LivingObjectPane source ownership is proven.
```

Replace with:

```text
            - [UID:0003EB][0x00630c24-0x00630c28.LivingObjectPaneActionNegativeOneFloatConstant](by-memory/0x00630c24-0x00630c28.LivingObjectPaneActionNegativeOneFloatConstant.md) 0x00630c24-0x00630c28 | float-constant | LivingObjectPaneActionNegativeOneFloatConstant : reconstructable : 88% : very-strong : Exact 4-byte IEEE-754 -1.0f scalar constant (bytes 00 00 80 bf / 0xbf800000) assigned to [UID:0000KU][LivingObjectPane](by-file/LivingObjectPane.md) after B001 split the raw action-tail helper [UID:0003H5][0x005acb20-0x005acc23.LivingObjectPaneAutoFaceDirectionPacketRawHelper](by-memory/0x005acb20-0x005acc23.LivingObjectPaneAutoFaceDirectionPacketRawHelper.md); all four movss refs are now accounted for in LivingObjectPane action/facing packet code at 0x005acbbd, 0x005acbdc, 0x005accf9, and 0x005acd18.
```

## Concrete Next Actions

1. Supervisor applies the coverage-report row edits above.
2. Supervisor can close `0003EB` as ownership resolved and move this report to `research/executed/` after applying rows.
3. No further split is recommended for [UID:0003EB]. Future work may still name/reconstruct the broader raw `0x005ac7e0` / `0x005ac9a0` action-tail region, but that is no longer required for the `-1.0f` scalar ownership decision.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003EB","source_path":"executed-b-agent-research/B001/0003EB-LivingObjectPaneActionNegativeOneFloatConstant.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
