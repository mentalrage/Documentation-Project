** TARGET-REPORT-UID:00037G **
** AUTHOR-AGENT-ID:B010 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00037G TextMenuItemListDestructorThunks Source Routing Report

Status: FINISHED report-only checkpoint for [UID:00037G] `TextMenuItemListDestructorThunks`.

Target path: `E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x00520b55-0x00520b6a.TextMenuItemListDestructorThunks.md`

Required report path: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B010\research\00037G-TextMenuItemListDestructorThunks-source-routing.md`

## Current Recommendation

- Keep [UID:00037G] non-reconstructable and non-emitting: `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank formal `RECONSTRUCTION_CPP`.
- Raise target metadata from `83/91` to `88/92` after incorporating the exact thunk inventory, vtable-only reachability, scalar-deleting-destructor flow, and source no-code proof.
- Source-facing owner context is resolved as [UID:0000ET] `TextMenuItemList` under [UID:0000OP] `TextMenuDialogs`, but this exact child should not use that class as canonical/emitter metadata because the bytes are MSVC-generated adjusted deleting-destructor thunks rather than handwritten source.
- Exact function boundaries are:
  - `0x00520b55-0x00520b60`: secondary vtable adjusted deleting-destructor thunk, vtable slot at `0x0061edd0[0]`, forwards to `0x00520df0`.
  - `0x00520b60-0x00520b6b`: tertiary vtable adjusted deleting-destructor thunk, vtable slot at `0x0061ee00[0]`, forwards to `0x00520df0`.
  - Combined half-open range is `0x00520b55-0x00520b6b`; `0x00520b6a` is the last byte of the second thunk.
- Recommend a range/filename normalization from `0x00520b55-0x00520b6a.TextMenuItemListDestructorThunks.md` to `0x00520b55-0x00520b6b.TextMenuItemListDestructorThunks.md` if the supervisor wants strict half-open by-memory naming. If the rename is deferred to a coordinated cleanup of sibling Batch166 thunk pages, the target prose must still document the actual half-open range and last-byte caveat.
- No first-draft C++ should be populated in this target. The source should declare the normal `TextMenuItemList`/`ListPane` destructor shape; the compiler regenerates the secondary/tertiary thunks from class layout and vtables.

## Target

- Target UID: `00037G`
- Current target path: `source-3/project-documentation/by-memory/0x00520b55-0x00520b6a.TextMenuItemListDestructorThunks.md`
- Current score: `COMPLETION:83`, `CONFIDENCE:91`
- Current metadata: `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank C++.
- Parent aggregate: [UID:0001BX] `by-memory/0x00520abb-0x00520e2b.MenuDialogDestructorThunks.md`
- Source context: [UID:0000ET] `by-class/TextMenuItemList.md`, [UID:0000OP] `by-file/TextMenuDialogs.md`
- Vtable support: [UID:00031Y] `by-type/by-vtable/TextMenuDialogVtables.md`, [UID:0001Y5] `by-type/by-vtable/MerchantMenuDialogVtableFamily.md`
- Scalar wrapper neighbor: [UID:00037H] `by-memory/0x00520df0-0x00520e2b.TextMenuItemListScalarDeletingDestructor.md`

## Evidence Checked

- Read the assigned target, parent aggregate, source owner class/file docs, vtable docs, scalar destructor support page, coverage rows, ignored ledger, local exports, and sibling thunk pages.
- Attempted live IDA MCP at `127.0.0.1:13337`; unavailable in this session (`Unable to connect to the remote server`). Current conclusions therefore distinguish prior live IDA evidence recorded in by-* docs from local export JSON checks.
- Existing executed B-agent research search for `00037G`, `TextMenuItemListDestructorThunks`, `00520b55`, and `00520b60` under B001/B002/B010 `research/executed` found no prior executed report for this exact target.
- Local export JSON evidence:
  - `exports/00520b55.json`: function at `0x00520b55`, size `11`, signature `virt_meth_0x520b55(TextMenuItemList * this, uint param_1)`, no ordinary callers, one callee `0x00520df0` `~TextMenuItemList`, decompilation failed.
  - `exports/00520b60.json`: function at `0x00520b60`, size `11`, same signature shape, no ordinary callers, one callee `0x00520df0`, decompilation failed.
  - `exports/00520df0.json`: scalar deleting destructor at `0x00520df0`, size `59`, callers from `0x00520b55` and `0x00520b60`, callees `0x004f3b60`, `0x004f4ac0`, and `0x0041b6a0`.
  - `exports/00519520.json`: `TextMenuItemList` constructor, size `97`, called from `TextMenuDialog`, callee `ListPane` constructor `0x004f3a50`.
  - `exports/_vtables.json`: `TextMenuItemList` primary vtable `0x0061ed48` has 33 slots with slot 0 -> `0x00520df0`; secondary vtable `0x0061edd0` has 11 slots with slot 0 -> `0x00520b55`; tertiary vtable `0x0061ee00` has 2 slots with slot 0 -> `0x00520b60`.
  - `exports/_globals.json`: vtable globals at `0x0061ed48`, `0x0061edd0`, and `0x0061ee00` each have constructor/store reference evidence from `0x00519520` `TextMenuItemList`.
- Existing by-* live IDA evidence:
  - [UID:0001BX] records `lookup_funcs` confirming all listed thunks, including `0x00520b55` and `0x00520b60`, as size `0x0b` functions.
  - [UID:0001BX] records `xrefs_to 0x00520df0` code refs from `0x00520b55`/`0x00520b60` and primary vtable data ref `0x0061ed48`.
  - [UID:0001BX] records secondary/tertiary thunk data refs at `0x0061edd0` and `0x0061ee00`.
  - [UID:00031Y] records `TextMenuItemList` constructor stores to vtables `0x0061ed48`, `0x0061edd0`, and `0x0061ee00` at `0x00519560`, `0x00519566`, and `0x00519570`.
  - [UID:0001Y5] records the list-pane companion classes as using the larger list-pane vtable shape: 33 primary slots, 11 secondary slots, and 2 tertiary slots.

## Heuristic / Inference Reanalysis And Validation

### Exact Thunk Boundaries

The current target filename/status uses `0x00520b55-0x00520b6a`. Local exports and parent live IDA evidence both show two adjacent 0x0b functions:

| Function | Size | Half-open range | Last byte | Role |
| --- | --- | --- | --- | --- |
| `virt_meth_0x520b55` | `0x0b` | `0x00520b55-0x00520b60` | `0x00520b5f` | secondary vtable adjusted deleting-destructor thunk |
| `virt_meth_0x520b60` | `0x0b` | `0x00520b60-0x00520b6b` | `0x00520b6a` | tertiary vtable adjusted deleting-destructor thunk |

Decision: the source-quality range is the half-open `0x00520b55-0x00520b6b`. The existing filename appears to encode the last byte of the pair, consistent with sibling Batch166 pages [UID:00037A], [UID:00037C], and [UID:00037E], but inconsistent with normal half-open by-memory naming and with [UID:0001BY]/[UID:0001BZ] style. Recommend correcting this target to `...0x00520b6b...` during implementation or at least documenting the actual half-open range in prose.

### Scalar Deleting Destructor Flow

The thunks do not contain a destructor body. They tail-forward to [UID:00037H] `0x00520df0-0x00520e2b.TextMenuItemListScalarDeletingDestructor`.

`0x00520df0` is the primary-vtable deleting destructor wrapper:

- Primary vtable `0x0061ed48[0]` -> `0x00520df0`.
- Code callers are only the two adjusted thunks `0x00520b55` and `0x00520b60` in local export evidence.
- Callees in local export evidence are `0x004f3b60`, `0x004f4ac0`, and guard/check helper `0x0041b6a0`, matching the expected wrapper pattern: perform ordinary list-pane/base cleanup, then conditionally delete the object under scalar-delete flags.
- Source-facing action is a normal `TextMenuItemList` destructor/class layout, not standalone thunk source.

Decision: [UID:00037G] should document relationship to [UID:00037H] but remain blank C++. If [UID:00037H] is later improved, it should also stay non-emitting wrapper glue unless the class page emits a normal destructor declaration/body.

### Vtable Refs And Reachability

Reachability is vtable-only:

- `0x00520b55` appears at `TextMenuItemList` secondary vtable `0x0061edd0` slot 0.
- `0x00520b60` appears at `TextMenuItemList` tertiary vtable `0x0061ee00` slot 0.
- Both vtable globals are referenced/stored by the `TextMenuItemList` constructor at `0x00519520`.
- Local export JSON reports no ordinary callers for either thunk.
- The scalar wrapper `0x00520df0` is primary vtable slot 0 at `0x0061ed48` and has code refs from the two thunks.

Decision: these are not private source methods. Best source-facing names are descriptive compiler names such as `TextMenuItemList secondary deleting-destructor adjustor thunk` and `TextMenuItemList tertiary deleting-destructor adjustor thunk`.

### Source Destructor / List Inheritance Shape

[UID:0000ET] `TextMenuItemList` is the private scrollable row-list companion used by `TextMenuDialog`. Constructor evidence ties it to `ListPane`, and the vtable family shows the same three-view list-pane shape used by related menu-list classes:

- primary list-pane view with 33 slots;
- secondary view with 11 slots;
- tertiary view with 2 slots.

The sibling menu-list thunk pages [UID:0001BY] and [UID:0001BZ], plus shared default thunk docs [UID:0001BW]/[UID:00023N], establish the recurring adjusted-this pattern: secondary thunks subtract `0xa0` and tertiary thunks subtract `0xa4` before forwarding. Because [UID:00037G] has the same list companion secondary/tertiary vtable positions and same 0x0b thunk layout, the strongest source-quality inference is that `0x00520b55` is the `this - 0xa0` adjustor and `0x00520b60` is the `this - 0xa4` adjustor for `TextMenuItemList`.

Decision: source docs should describe the deltas as the menu-list/list-pane inherited layout pattern. Do not invent C++ members for these thunks.

### Aggregate Thunk Island Placement

[UID:0001BX] is correctly a mixed non-reconstructable index over compiler glue. It spans:

- argumented menu-list thunks/destructor;
- text-input menu dialog thunks/destructor;
- text-menu dialog thunks/destructor;
- text-menu item-list thunks/destructor;
- neighboring shared item/spell/object-image/default glue documented separately.

Decision: keep [UID:0001BX] as an audit/index page with no owner/emitter. Exact child [UID:00037G] should remain child/context evidence for `TextMenuItemList`, not cause the aggregate to attach to [UID:0000OP].

### Rejected Alternatives

- Rejected: emit `TextMenuItemList::virt_meth_0x520b55` / `virt_meth_0x520b60` as source methods. These are vtable destructor adjustor thunks and have no ordinary callers.
- Rejected: set [UID:00037G] `CANONICAL_OWNER:0000ET` and `EMITTER_UIDS:0000ET` or `0000OP`. That would treat compiler-generated bytes as source output. Prose owner context is enough.
- Rejected: merge [UID:00037G] into [UID:00037H]. The thunks and scalar wrapper are distinct functions and distinct vtable slots; [UID:00037H] models the primary deleting destructor wrapper.
- Rejected: attach the parent aggregate [UID:0001BX] to `TextMenuDialogs`. The aggregate is physically mixed across several source owner families.
- Rejected: treat the existing `0x00520b55-0x00520b6a` endpoint as a complete half-open range. It misses the second thunk's last byte if read as half-open; use `0x00520b6b` as the half-open endpoint or explicitly state that `0x00520b6a` is the last byte.

## Ownership And Metadata Recommendation

Recommended target metadata after implementation:

```text
COMPLETION:88
CONFIDENCE:92
CANONICAL_OWNER:NONE
RECONSTRUCTABLE:FALSE
EMITTER_UIDS:
RECONSTRUCTION_CPP: blank
```

Rationale:

- Completion rises because the target can record exact function boundaries, vtable slots, scalar wrapper target, constructor vtable store evidence, source/no-code policy, and range endpoint correction.
- Confidence rises because prior live IDA evidence and current local exports agree on the thunk starts, sizes, target destructor, vtable-only reachability, and class source context.
- Score remains below final-audit levels because live IDA was unavailable in this B010 session, `0x00520b55`/`0x00520b60` decompilation fails in the local exports, and the exact byte deltas for this specific pair should ideally be reconfirmed directly when IDA is available even though the inherited list-thunk pattern is strong.

## First-Draft C++ Recommendation

Do not populate [UID:00037G] formal C++.

The source-facing shape belongs in `TextMenuItemList`/`TextMenuDialogs` docs, not in this target:

```cpp
// Source-shape context only; do not insert into UID 00037G.
class TextMenuItemList : public ListPane {
public:
    virtual ~TextMenuItemList();
    // constructor, AddTextEntry, selection-state forwarder, DrawListItem...
};
```

The compiler should regenerate:

- primary scalar deleting destructor pointer at `0x0061ed48[0]`;
- secondary adjusted deleting-destructor thunk at `0x0061edd0[0]`;
- tertiary adjusted deleting-destructor thunk at `0x0061ee00[0]`.

## Future By-* Implementation Checklist

If accepted by supervisor, lease all edited by-* docs first. Do not edit `by-memory/-coverage-report.md`.

1. Update target [UID:00037G]:
   - Preferred: rename/move to `by-memory/0x00520b55-0x00520b6b.TextMenuItemListDestructorThunks.md` and update the title/address range accordingly.
   - If rename is deferred, keep the current file path but add a prominent boundary note: actual half-open range is `0x00520b55-0x00520b6b`; `0x00520b6a` is the last byte.
   - Change score `83/91 -> 88/92`.
   - Keep `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank C++.
   - Add a covered-functions table with the two 0x0b thunks and vtable slot refs `0x0061edd0[0]` and `0x0061ee00[0]`.
   - Add no-code proof: vtable-only reachability, compiler-generated adjusted deleting destructor role, scalar wrapper handled by [UID:00037H], source destructor belongs to class declaration/layout.

2. Update [UID:0001BX] `MenuDialogDestructorThunks`:
   - Correct the child link/range for [UID:00037G] to the half-open endpoint if the file is renamed.
   - Add a note that the Batch166 child endpoint was last-byte-style and B010 confirmed the actual combined half-open range.
   - Preserve aggregate `RECONSTRUCTABLE:FALSE`, `CANONICAL_OWNER:NONE`, blank emitter/C++.

3. Update [UID:00037H] `TextMenuItemListScalarDeletingDestructor`:
   - Add relationship detail that [UID:00037G] secondary/tertiary vtable thunks forward here, while the primary vtable `0x0061ed48[0]` points here directly.
   - Keep [UID:00037H] non-emitting compiler wrapper glue unless a separate accepted report changes its policy.

4. Update [UID:0000ET] `TextMenuItemList`:
   - Replace stale `95/95 reconstruction-code bar` wording with current source policy language.
   - Clarify that the thunk pages are no-body compiler artifacts; source should model the class/list-pane inheritance and ordinary destructor shape.
   - Add the exact `TextMenuItemList` vtable destructor layout: primary `0x0061ed48[0] -> 0x00520df0`, secondary `0x0061edd0[0] -> 0x00520b55`, tertiary `0x0061ee00[0] -> 0x00520b60`.

5. Update [UID:0000OP] `TextMenuDialogs`:
   - Keep source file owner as `ui/dialogs/TextMenuDialogs.cpp`.
   - In the proposed contents row for `TextMenuItemList`, change destructor island wording to the exact no-body compiler-generated destructor support: thunks `0x00520b55-0x00520b6b` plus scalar wrapper `0x00520df0-0x00520e2b`.

6. Update [UID:00031Y] `TextMenuDialogVtables` and/or [UID:0001Y5] `MerchantMenuDialogVtableFamily` only if desired:
   - Add direct links from the `TextMenuItemList` secondary/tertiary vtable slot 0 entries to [UID:00037G], and primary slot 0 to [UID:00037H].
   - Existing vtable basis is already strong, so this is support enrichment rather than required for the target.

7. Update `by-memory/-ignored.md`:
   - Refine `0x00520b13-0x00520b6b` to list [UID:00037G] explicitly and state the exact `TextMenuItemList` thunk pair is `0x00520b55-0x00520b6b`.
   - Do not manually edit `by-memory/-coverage-report.md`; use the exact row text below.

8. Optional follow-up outside this target:
   - Sibling Batch166 pages [UID:00037A], [UID:00037C], and [UID:00037E] appear to use last-byte endpoints in their filenames/titles. A coordinated range-normalization pass should review them separately; do not fold that into this implementation unless the supervisor explicitly includes it.
   - The gap `0x00520b6b-0x00520b70` should be byte-verified when IDA is available. It is likely alignment before [UID:0001C0], but this report does not claim it as padding without a byte check.

## Exact Pending Coverage Row Text

Recommended exact [UID:00037G] row after half-open filename/range correction:

```text
        - [UID:00037G][0x00520b55-0x00520b6b.TextMenuItemListDestructorThunks](by-memory/0x00520b55-0x00520b6b.TextMenuItemListDestructorThunks.md) 0x00520b55-0x00520b6b | compiler adjustor thunks | TextMenuItemListDestructorThunks : ignored/non-emitting : 88% : very strong : B010 source-routing recheck resolves this as the two MSVC-generated `TextMenuItemList` adjusted deleting-destructor thunks: `0x00520b55-0x00520b60` is the secondary vtable slot `0x0061edd0[0]` thunk and `0x00520b60-0x00520b6b` is the tertiary vtable slot `0x0061ee00[0]` thunk; both are 0x0b-byte functions with no ordinary callers and both forward to [UID:00037H][0x00520df0-0x00520e2b.TextMenuItemListScalarDeletingDestructor](by-memory/0x00520df0-0x00520e2b.TextMenuItemListScalarDeletingDestructor.md). Primary vtable `0x0061ed48[0]` points directly to the scalar wrapper, and `TextMenuItemList` constructor evidence stores all three vtable views. Keep `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank emitter/C++; source should declare the normal `TextMenuItemList`/`ListPane` destructor shape and let the compiler regenerate these thunks.
```

Fallback row if the supervisor defers the filename rename but accepts the prose update:

```text
        - [UID:00037G][0x00520b55-0x00520b6a.TextMenuItemListDestructorThunks](by-memory/0x00520b55-0x00520b6a.TextMenuItemListDestructorThunks.md) 0x00520b55-0x00520b6b | compiler adjustor thunks | TextMenuItemListDestructorThunks : ignored/non-emitting : 88% : very strong : B010 source-routing recheck resolves this as the two MSVC-generated `TextMenuItemList` adjusted deleting-destructor thunks; the file name uses the current last-byte endpoint, but the actual half-open range is `0x00520b55-0x00520b6b` (`0x00520b6a` is the last byte). `0x00520b55-0x00520b60` is the secondary vtable slot `0x0061edd0[0]` thunk and `0x00520b60-0x00520b6b` is the tertiary vtable slot `0x0061ee00[0]` thunk; both are 0x0b-byte functions with no ordinary callers and both forward to [UID:00037H][0x00520df0-0x00520e2b.TextMenuItemListScalarDeletingDestructor](by-memory/0x00520df0-0x00520e2b.TextMenuItemListScalarDeletingDestructor.md). Keep `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank emitter/C++; source should declare the normal `TextMenuItemList`/`ListPane` destructor shape and let the compiler regenerate these thunks.
```

Suggested surrounding coverage context replacement, if the supervisor refreshes the stale [UID:0001BX] block:

```text
    - [UID:0001BX][0x00520abb-0x00520e2b.MenuDialogDestructorThunks](by-memory/0x00520abb-0x00520e2b.MenuDialogDestructorThunks.md) 0x00520abb-0x00520e2b | destructor/thunk island | MenuDialogDestructorThunks : ignored/non-emitting : 87% : strong : Reviewed mixed compiler-generated destructor/thunk index for argumented-menu and text-menu dialog/list classes plus neighboring shared glue; exact child pages carry owner-specific thunk/scalar-wrapper evidence, while this aggregate stays `RECONSTRUCTABLE:FALSE`, `CANONICAL_OWNER:NONE`, blank emitter/C++ because no single source owner covers the island.
        - [UID:00037G][0x00520b55-0x00520b6b.TextMenuItemListDestructorThunks](by-memory/0x00520b55-0x00520b6b.TextMenuItemListDestructorThunks.md) 0x00520b55-0x00520b6b | compiler adjustor thunks | TextMenuItemListDestructorThunks : ignored/non-emitting : 88% : very strong : B010 source-routing recheck resolves this as the two MSVC-generated `TextMenuItemList` adjusted deleting-destructor thunks: `0x00520b55-0x00520b60` is the secondary vtable slot `0x0061edd0[0]` thunk and `0x00520b60-0x00520b6b` is the tertiary vtable slot `0x0061ee00[0]` thunk; both are 0x0b-byte functions with no ordinary callers and both forward to [UID:00037H][0x00520df0-0x00520e2b.TextMenuItemListScalarDeletingDestructor](by-memory/0x00520df0-0x00520e2b.TextMenuItemListScalarDeletingDestructor.md). Primary vtable `0x0061ed48[0]` points directly to the scalar wrapper, and `TextMenuItemList` constructor evidence stores all three vtable views. Keep `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank emitter/C++; source should declare the normal `TextMenuItemList`/`ListPane` destructor shape and let the compiler regenerate these thunks.
```

## Validation Commands Needed If Accepted

Run from `E:\NTK\GhidraBridge\source-3\project-documentation`.

Minimum if the target is edited without rename:

> Executable block R001 was removed from this report and preserved verbatim in [00037G-TextMenuItemListDestructorThunks-source-routing-removed.md](00037G-TextMenuItemListDestructorThunks-source-routing-removed.md). The archived block is non-authoritative and must not be executed.

If the target is renamed, validate the new path and any support docs whose links changed:

> Executable block R002 was removed from this report and preserved verbatim in [00037G-TextMenuItemListDestructorThunks-source-routing-removed.md](00037G-TextMenuItemListDestructorThunks-source-routing-removed.md). The archived block is non-authoritative and must not be executed.

No validator was run for this report-only checkpoint because no target/support by-* docs were edited.

## IDA Rename / Type / Comment Recommendations

- `0x00520b55`: rename/comment as `TextMenuItemList_secondary_dtor_adjustor_thunk` or `TextMenuItemList_dtor_adjustor_thunk_secondary`. Confidence: high, descriptive rather than proven original.
- `0x00520b60`: rename/comment as `TextMenuItemList_tertiary_dtor_adjustor_thunk`. Confidence: high, descriptive rather than proven original.
- `0x00520df0`: keep/source-quality name `TextMenuItemList_scalar_deleting_destructor` or `TextMenuItemList::scalar_deleting_destructor`. Confidence: high.
- `0x0061ed48`: label as `TextMenuItemList` primary vtable; slot 0 points to scalar deleting destructor. Confidence: high.
- `0x0061edd0`: label as `TextMenuItemList` secondary vtable; slot 0 points to [UID:00037G] secondary thunk. Confidence: high.
- `0x0061ee00`: label as `TextMenuItemList` tertiary vtable; slot 0 points to [UID:00037G] tertiary thunk. Confidence: high.
- Add repeatable comments to both thunks: `MSVC generated adjusted deleting-destructor thunk; vtable-only; do not reconstruct as a source method.` Confidence: high.

## Open Questions With Attempted Resolution

- Exact byte deltas for [UID:00037G] target-specific thunks:
  - Best answer: secondary `this - 0xa0`, tertiary `this - 0xa4`.
  - Evidence: recurring menu-list/list-pane thunk pattern in [UID:0001BY], [UID:0001BZ], [UID:0001BW], and [UID:00023N]; same vtable view shape and 0x0b function sizes; parent [UID:0001BX] records the same adjustor-thunk family.
  - Limitation: live IDA was unavailable and local decompilation for `0x00520b55`/`0x00520b60` failed, so this should be directly byte-confirmed during a future IDA-available implementation/audit. This does not block the no-code/source-routing conclusion.
- Should metadata owner be `0000ET` because the vtables are `TextMenuItemList`?
  - Rejected for metadata. The source context is `TextMenuItemList`, but the exact target is compiler glue. Use prose source context, keep canonical owner/emitter blank.
- Should this target emit a comment-only C++ marker?
  - Rejected. The current formal C++ block should remain blank. A comment marker would create source-output noise for compiler-generated vtable support; the source class declaration should carry the real destructor semantics.
- Should [UID:0001BX] become a `TextMenuDialogs` child?
  - Rejected. [UID:0001BX] is a mixed island. [UID:00037G] has text-menu context, but the aggregate includes argumented and neighboring shared glue.

## Changed Files

Created:

- `source-3/project-documentation/tools/leaser/Agents/Agent-B010/research/00037G-TextMenuItemListDestructorThunks-source-routing.md`

Modified:

- None. Report-only task; no target/support by-* docs and no `by-memory/-coverage-report.md` edits were made.

Leases used:

- None. Creating this report inside the Agent-B010 research folder does not require a lease.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B010","command_id":"000000004165","destination_path":"executed-b-agent-research/B010/00037G-TextMenuItemListDestructorThunks-source-routing.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:34","uid":"00037G"} -->
<!-- {"agent":"B010","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00037G-TextMenuItemListDestructorThunks-source-routing-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B010/00037G-TextMenuItemListDestructorThunks-source-routing.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00037G"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
