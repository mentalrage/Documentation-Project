** TARGET-REPORT-UID:00021B **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00021B ClanStatusPaneConstructorCleanup Source-Routing Report

Agent: `Agent-B004`
Assignment: [UID:00021B] `ClanStatusPaneConstructorCleanup`
Target: `source-3/project-documentation/by-memory/0x00484230-0x004842ad.ClanStatusPaneConstructorCleanup.md`
Required mode: report-only. I did not edit by-* documentation and did not edit `by-memory/-coverage-report.md`.

Report status: FINISHED.

## Recommendation

Keep [UID:00021B] as non-reconstructable compiler cleanup:

```text
COMPLETION:84
CONFIDENCE:88
CANONICAL_OWNER:NONE
RECONSTRUCTABLE:FALSE
EMITTER_UIDS:
RECONSTRUCTION_CPP: blank
```

This range is best documented as MSVC constructor-unwind cleanup for [UID:00010A] `ClanStatusPane::ClanStatusPane()`, not as a source method, not as a destructor entry point, and not as child-pane-owned source. The ordinary constructor and destructor documents cover the source semantics; emitting this fragment would duplicate compiler-generated partial-construction cleanup.

The current score is appropriate. Completion should stay below the normal first-draft C++ gate because this is not a source entity and has no formal C++ block. Confidence should stay below final-audit/95 because this B004 pass could not query live IDA MCP EH metadata, and no direct EH table owner for the cleanup fragment was exposed in the local PE scan. The no-code conclusion itself is strong.

## Evidence Checked

Instructions and workflow:

- `source-3/project-documentation/tools/leaser/Agents/Supervisor.md`
- `.codex/AGENTS.md`
- `source-3/project-documentation/tools/leaser/Agents/Agent-B004/goal.md`

Target/support documentation:

- `by-memory/0x00484230-0x004842ad.ClanStatusPaneConstructorCleanup.md`
- `by-memory/0x00484030-0x00484221.ClanStatusPaneConstructor.md`
- `by-class/ClanStatusPane.md`
- `by-file/Clan.md`
- `by-memory/0x0048c260-0x0048c63f.ClanDestructorBand.md`
- `by-memory/0x0048c590-0x0048c63f.ClanStatusPaneDestructor.md`
- `by-memory/0x0048c32b-0x0048c341.ClanStatusPaneDestructorAdjustorThunks.md`
- `by-memory/0x00615570-0x006158f4.ClanPaneListVtableData.md`
- `by-memory/0x0067ade4-0x0067ade8.g_pClanStatusPane.md`
- `by-class/ClanInfoListPane.md`
- `by-class/ClanJoinListPane.md`
- `by-class/ClanEnlistListPane.md`
- `tools/leaser/Agents/Agent-B014/research/executed/00010A-ClanStatusPaneConstructor-source-quality.md`
- `by-memory/-coverage-report.md`, `auto-generated/-ag-memory-coverage.md`, and `project-level/-auto-completion-stats.md` for current rows only.

Tooling/evidence:

- Live IDA MCP was unavailable from this session: the direct endpoint request could not connect. I did not claim fresh live IDA results beyond existing IDA-backed docs. The removed literal PowerShell command is preserved only in the linked inert archive.
- Local PE/Capstone check used `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`, `md5=4247e04e20b65d6414c7238aa8ff5515`.
- The PE sections are `.text 0x00401000-0x0060c600`, `.rdata 0x0060d000-0x0066c200`, `.data 0x0066d000-0x0069ce24`, `.rsrc 0x0069d000-0x006b2e00`.

## Boundary And Liveness Findings

The exact raw range is `0x00484230-0x004842ad` half-open, length `0x7d`.

Local byte/disassembly audit confirms:

- Predecessor constructor tail ends at `0x00484221 ret`; the function end is end-exclusive `0x00484222`.
- `0x00484222-0x00484230` is fourteen `0xcc` bytes.
- `0x00484230-0x004842ad` is the cleanup fragment.
- `0x004842ad-0x004842b0` is three `0xcc` bytes.
- The next real function starts at `0x004842b0` (`ClanAttributePacketParser` / `sub_4842B0` in older labels).
- The exact cleanup byte pattern appears once in the image.

The local scan found no direct liveness route to the cleanup start/range:

- No full-file dword hits for absolute VA `0x00484230`.
- No full-file dword hits for RVA `0x00084230`.
- No full-file dword hits for any absolute VA inside `0x00484230-0x004842ad`.
- No opcode-shaped `call`, `jmp`, or near-conditional branch target to `0x00484230` or any address inside the cleanup range.
- The nearby branch targets found by the scan are `0x00484fc8 -> 0x004842b0` for the parser and `0x0048c331/0x0048c33c -> 0x0048c590` for destructor adjustor thunks, not this cleanup fragment.

This agrees with the existing target doc's IDA-backed notes: no function object is defined at `0x00484230`, while the adjacent constructor and parser are real functions.

## Raw Cleanup Semantics

The fragment is entered with `ecx == this`, saves `esi`, and has no source-style prologue or return. It restores the `ClanStatusPane` vtable views, tears down child members that were already assigned, clears the singleton, then tail-jumps into base `Pane` teardown:

```asm
00484230  push esi
00484231  mov esi, ecx
00484233  mov ecx, [esi+0x2510]
00484239  mov [esi], 0x00615570
0048423f  mov [esi+0x0a0], 0x006155bc
00484249  mov [esi+0x0a4], 0x006155ec
00484253  test ecx, ecx
00484255  jz 0x00484267
00484257  mov eax, [ecx]
00484259  push 1
0048425b  call [eax]
0048425d  mov [esi+0x2510], 0
00484267  mov ecx, [esi+0x2514]
0048426d  test ecx, ecx
0048426f  jz 0x00484281
00484271  mov eax, [ecx]
00484273  push 1
00484275  call [eax]
00484277  mov [esi+0x2514], 0
00484281  mov ecx, [esi+0x2518]
00484287  test ecx, ecx
00484289  jz 0x0048429b
0048428b  mov eax, [ecx]
0048428d  push 1
0048428f  call [eax]
00484291  mov [esi+0x2518], 0
0048429b  mov ecx, esi
0048429d  mov [0x0067ade4], 0
004842a7  pop esi
004842a8  jmp 0x00544580
```

Resolved source-level names/roles:

| Binary evidence | Source-facing role | Confidence |
| --- | --- | --- |
| `0x00615570`, `0x006155bc`, `0x006155ec` stores | `ClanStatusPane` primary, secondary, and tertiary vtable restores | High; vtable data page records constructor, cleanup, destructor store xrefs. |
| `this+0x2510` | `m_infoListPane` (`ClanInfoListPane *`) | High; constructor/parser/refresh/destructor docs agree. |
| `this+0x2514` | `m_joinListPane` (`ClanJoinListPane *`) | High; constructor/parser/refresh/destructor docs agree. |
| `this+0x2518` | `m_enlistListPane` (`ClanEnlistListPane *`) | High; constructor/parser/refresh/destructor docs agree. |
| `mov eax, [ecx]; push 1; call [eax]` | virtual scalar-deleting destructor call with delete flag `1` on each child | High; exact pattern mirrors destructor. |
| `0x0067ade4` | `g_pClanStatusPane` | High; singleton storage page records this slot and 15 xrefs. |
| `jmp 0x00544580` | tail jump to base `Pane` teardown/destructor body | High for role, medium for final helper spelling; existing docs still carry raw `sub_544580` in several places. |

The child pointer fields are zeroed after each delete call. That is normal compiler cleanup/destructor hygiene, not a source-authored helper API.

## Constructor And Destructor Relationship

[UID:00010A] is the source constructor anchor. Its first-draft C++ is already accepted as:

```cpp
ClanStatusPane::ClanStatusPane()
    : Pane(1)
{
    g_pClanStatusPane = this;

    m_infoListPane = new ClanInfoListPane;
    m_infoListPane->SetMode(1);
    m_infoListPane->SetTextEditMode(FALSE, FALSE);

    m_joinListPane = new ClanJoinListPane;
    m_joinListPane->SetMode(1);

    m_enlistListPane = new ClanEnlistListPane;
    m_enlistListPane->SetMode(1);

    m_rawAttributeDataLength = 0;
}
```

That source shape explains why the compiler needs a hidden cleanup fragment: if construction fails after the base pane and some child panes have been created, the compiler must destroy the already-assigned children, clear the singleton written by the constructor body, and tear down the base pane.

[UID:00030P] `0x0048c590-0x0048c63f.ClanStatusPaneDestructor` is the runtime destructor anchor, not this fragment. The local PE check shows the destructor has a normal prologue, mirrors the same vtable restores and child cleanup, calls base teardown at `0x0048c60a`, then applies scalar-deleting destructor flags:

- `0x0048c59c`, `0x0048c5a2`, `0x0048c5ac`: same `ClanStatusPane` vtable triplet.
- `0x0048c596`, `0x0048c5ca`, `0x0048c5e4`: same child field loads.
- `0x0048c600`: same `g_pClanStatusPane` clear.
- `0x0048c60a`: call to `0x00544580`.
- `0x0048c331` and `0x0048c33c`: adjustor thunks route secondary/tertiary destructor views to `0x0048c590`, not to `0x00484230`.

Therefore the best source-level explanation is:

```text
ClanStatusPane::ClanStatusPane() ordinary source
  -> compiler-generated EH constructor cleanup at 0x00484230
ClanStatusPane::~ClanStatusPane() ordinary source/destructor anchor at 0x0048c590
```

Do not merge `0x00484230` into the constructor C++ block, and do not emit a `ClanStatusPane::CleanupConstructorFailure` method.

## Ownership And Source Placement Ranking

1. Compiler-generated constructor-unwind cleanup for [UID:00010A] `ClanStatusPane::ClanStatusPane()` - accepted. This is the direct binary/source-routing role.
2. [UID:00002K] `ClanStatusPane` and [UID:0000I8] `Clan` - accepted only as semantic/support context. They own the constructor/destructor source, but this cleanup row should keep `CANONICAL_OWNER:NONE` and no emitters because the fragment itself is compiler output.
3. [UID:00030P] `ClanStatusPaneDestructor` - rejected as the direct owner. The destructor mirrors the cleanup and proves field/vtable roles, but it has its own function, vtable entries, and scalar-deleting flags.
4. `ClanInfoListPane`, `ClanJoinListPane`, `ClanEnlistListPane` - rejected as owners. They are child pointer types being destroyed; the lifecycle field ownership is in `ClanStatusPane`.
5. `ClanPaneListVtableData`, `g_pClanStatusPane`, base `Pane` teardown, and `ClanDestructorBand` - rejected as source owners. They are data/helper/support evidence.
6. A standalone handwritten helper - rejected. There is no function object, no xref/caller route, no vtable entry, no return, and no reason for human source to name this one-off partial-construction cleanup.

## Target-Specific No-Code Proof

No formal C++ should be emitted for [UID:00021B]:

- The raw range has no IDA function object in current docs and no local PE evidence of a branch or dword reference to the start/range.
- The fragment is surrounded by `int3` padding and sits between the real constructor and the real parser function.
- The body lacks a normal source-method prologue/epilogue and ends with a tail jump to base `Pane` teardown.
- The operation sequence is exactly constructor-unwind/destructor cleanup: restore current-class vtables, delete any constructed child members, zero fields, clear singleton, tear down base.
- The same source-visible behavior is already represented by the ordinary constructor [UID:00010A] and destructor [UID:00030P].
- Emitting this as handwritten source would add an artificial method and duplicate compiler-generated exception cleanup that a C++ compiler should regenerate from normal member ownership.

Remaining uncertainty does not block the no-code decision:

- The precise compiler EH table owner was not directly observed in this session because live IDA MCP was unavailable and the local PE scan found no simple VA/RVA reference to the fragment.
- The final canonical spelling for `0x00544580` remains a broader `Pane` destructor/base-teardown naming issue, but the helper role in this fragment is clear.

## Recommended Target Changes

When accepted for implementation, update only the target prose unless the supervisor also wants the optional support cleanups below. Metadata should remain unchanged.

Recommended target edits:

- Keep the metadata as:

```text
COMPLETION:84
CONFIDENCE:88
CANONICAL_OWNER:NONE
RECONSTRUCTABLE:FALSE
EMITTER_UIDS:
```

- Change "Current owner: ClanStatusPane" wording to a less misleading split such as:

```text
- Canonical source owner: none; compiler-generated cleanup fragment
- Semantic context: [UID:00002K][ClanStatusPane](by-class/ClanStatusPane.md)
- Source route for the originating constructor/destructor: [UID:0000I8][Clan](by-file/Clan.md)
```

- Add the B004 local evidence:

```text
2026-06-19 B004 local PE/Capstone recheck against `NexusTK.exe` (`md5=4247e04e20b65d6414c7238aa8ff5515`) confirms the exact `0x00484230-0x004842ad` cleanup bytes appear once, with fourteen `0xcc` bytes at `0x00484222-0x00484230` and three at `0x004842ad-0x004842b0`. A full-image dword scan found no absolute VA/RVA references to `0x00484230` or any address inside the cleanup range, and a `.text` branch-shape scan found no call/jump/near-conditional branch target into the range.
```

- Add or refresh the no-code proof from this report.
- Keep references to [UID:00010A] as the constructor source anchor and [UID:00030P] as the ordinary destructor anchor.
- Keep `g_pClanStatusPane`, `m_infoListPane`, `m_joinListPane`, and `m_enlistListPane` as the preferred names.
- Preserve exact half-open range `0x00484230-0x004842ad`; do not merge into the constructor or parser and do not split the fragment.

## Recommended Support Changes

Required support changes are minimal because the current class/file/constructor/destructor docs already agree that [UID:00021B] is compiler cleanup.

Support docs with no required change:

- `by-class/ClanStatusPane.md`: already identifies the cleanup as compiler-generated and not handwritten source.
- `by-file/Clan.md`: already routes the source through `Clan.cpp` and says cleanup is non-reconstructable constructor-unwind glue.
- `by-memory/0x00484030-0x00484221.ClanStatusPaneConstructor.md`: already explains ordinary constructor source and excludes [UID:00021B].
- `by-memory/0x0048c590-0x0048c63f.ClanStatusPaneDestructor.md`: already records destructor/cleanup mirroring.
- `by-memory/0x00615570-0x006158f4.ClanPaneListVtableData.md`: already records the relevant vtable store xrefs.
- `by-memory/0x0067ade4-0x0067ade8.g_pClanStatusPane.md`: already records the singleton storage role.

Support docs with stale wording to fix if an implementation callback allows support edits:

`by-class/ClanInfoListPane.md`

Replace the inline setup row with:

```markdown
| inline setup in `ClanStatusPane` constructor | `0x004840b2-0x00484135` | Allocates the 372-byte `TextEditPane` child, installs `ClanInfoListPane` vtables, stores it at `ClanStatusPane + 0x2510`, calls `Pane::SetMode(1)`, and applies the TextEditPane read-only/inactive mode setup. |
```

`by-class/ClanJoinListPane.md`

Replace the inline setup row with:

```markdown
| inline setup in `ClanStatusPane` constructor | `0x0048413f-0x0048419b` | Allocates the 332-byte `ListPane` child, installs `ClanJoinListPane` vtables, stores it at `ClanStatusPane + 0x2514`, and calls `Pane::SetMode(1)`. |
```

`by-class/ClanEnlistListPane.md`

Replace the inline setup row with:

```markdown
| inline setup in `ClanStatusPane` constructor | `0x004841a0-0x00484201` | Allocates the 332-byte `ListPane` child, installs `ClanEnlistListPane` vtables, stores it at `ClanStatusPane + 0x2518`, and calls `Pane::SetMode(1)`. |
```

These rows fix the lingering "shows it" wording. The constructor and `ClanStatusPane` docs already use `Pane::SetMode(1)`.

## Exact Pending Coverage Text

Do not edit `by-memory/-coverage-report.md` directly. No score/metadata coverage change is required, but if the supervisor wants the row to reflect this B004 recheck, replace the current [UID:00021B] row with this exact text:

```text
    - [UID:00021B][0x00484230-0x004842ad.ClanStatusPaneConstructorCleanup](by-memory/0x00484230-0x004842ad.ClanStatusPaneConstructorCleanup.md) 0x00484230-0x004842ad | constructor cleanup | ClanStatusPaneConstructorCleanup : ignored : 84% : strong : B004 2026-06-19 source-routing recheck keeps this as non-reconstructable MSVC constructor-unwind cleanup for [UID:00010A] `ClanStatusPane::ClanStatusPane`; local PE/Capstone evidence confirms the unique raw `0x00484230-0x004842ad` fragment, `0xcc` padding at `0x00484222-0x00484230` and `0x004842ad-0x004842b0`, no dword or branch references to the cleanup start/range, `ClanStatusPane` vtable restores, scalar-deleting child cleanup of `m_infoListPane`/`m_joinListPane`/`m_enlistListPane`, `g_pClanStatusPane` clear, and tail jump to base `Pane` teardown `0x00544580`; source remains covered by the ordinary constructor/destructor with no emitted C++ for this fragment.
```

## Future Implementation Checklist

1. Edit `by-memory/0x00484230-0x004842ad.ClanStatusPaneConstructorCleanup.md`.
2. Keep metadata unchanged: `84/88`, owner `NONE`, `RECONSTRUCTABLE:FALSE`, no emitters, blank C++.
3. Add B004 local PE evidence, no-direct-reference scan, exact range/padding proof, and target-specific no-code proof.
4. Clarify "canonical source owner none; semantic context ClanStatusPane; originating source route Clan.cpp" so metadata and prose do not conflict.
5. Optionally edit the three child class docs listed above to replace stale "shows it" wording with `Pane::SetMode(1)`.
6. Do not edit `by-memory/-coverage-report.md`; leave the exact row above for supervisor-owned coverage application.
7. No generated C++ or autogen source should change, because the formal C++ block remains blank and no emitter is assigned.

## Validation Commands Needed

Run from `source-3/project-documentation` after implementation:

> Executable block R001 was removed from this report and preserved verbatim in [00021B-ClanStatusPaneConstructorCleanup-source-routing-removed.md](00021B-ClanStatusPaneConstructorCleanup-source-routing-removed.md). The archived block is non-authoritative and must not be executed.

If the optional child support rows are edited, also run:

> Executable block R002 was removed from this report and preserved verbatim in [00021B-ClanStatusPaneConstructorCleanup-source-routing-removed.md](00021B-ClanStatusPaneConstructorCleanup-source-routing-removed.md). The archived block is non-authoritative and must not be executed.

If `by-class/ClanStatusPane.md`, `by-file/Clan.md`, `by-memory/-ignored.md`, constructor, destructor, singleton, or vtable docs are touched during implementation, run the same scoped validator command for each touched file.

No autogen/rescore workflow is expected unless metadata or formal C++ is changed despite this recommendation.

## IDA Rename, Type, And Comment Recommendations

Do not create or promote a source function named for `0x00484230` unless an IDA cleanup/EH annotation workflow requires a local-only name. If a local label/comment is useful, use a non-source name such as:

```text
ClanStatusPane_ctor_unwind_cleanup
```

Recommended comments/types:

| Item | Recommendation | Confidence |
| --- | --- | --- |
| `0x00484230-0x004842ad` | Comment: compiler-generated `ClanStatusPane` constructor-unwind cleanup; no handwritten source method. | High |
| `dword_67ADE4` / `0x0067ade4` | Name/type as `g_pClanStatusPane`, `ClanStatusPane *`. | High |
| `ClanStatusPane + 0x2510` | `ClanInfoListPane *m_infoListPane`. | High |
| `ClanStatusPane + 0x2514` | `ClanJoinListPane *m_joinListPane`. | High |
| `ClanStatusPane + 0x2518` | `ClanEnlistListPane *m_enlistListPane`. | High |
| `0x00615570`, `0x006155bc`, `0x006155ec` | Keep as `ClanStatusPane` primary/secondary/tertiary vtable views/COL-owned vtable data. | High |
| child `call [eax]` sites | Treat as scalar-deleting destructor virtual slot calls with delete flag `1`. | High |
| `0x00544580` | Use the current project canonical name for base `Pane` teardown/destructor body; do not invent a `ClanStatusPane` helper name for it. | Medium-high |

## Open Questions Closed Or Bounded

- Direct construction/cleanup caller: no source caller exists. Local scan found no branch or pointer route to the cleanup range; existing docs report no IDA function object. Best inference is compiler EH cleanup.
- Raw cleanup boundaries: solved as exact half-open `0x00484230-0x004842ad`, with `int3` padding on both sides.
- Vtable restores: solved as `ClanStatusPane` vtable views, not source-authored assignments.
- Child offsets: solved as `m_infoListPane`, `m_joinListPane`, and `m_enlistListPane`.
- Singleton clear: solved as `g_pClanStatusPane = NULL` in cleanup/destructor terms, compiler-generated for constructor failure here.
- Base teardown jump: solved as base `Pane` teardown role; final helper spelling remains a shared Pane naming issue, not a blocker.
- Owner/emitter: solved as no canonical owner/emitter for this fragment. `ClanStatusPane`/`Clan.cpp` are semantic context for the source constructor and destructor only.
- First-draft C++ readiness: solved as no-code. The target is documentation-ready, not C++-emitting.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000004165","destination_path":"executed-b-agent-research/B004/00021B-ClanStatusPaneConstructorCleanup-source-routing.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:29","uid":"00021B"} -->
<!-- {"agent":"B004","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00021B-ClanStatusPaneConstructorCleanup-source-routing-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B004/00021B-ClanStatusPaneConstructorCleanup-source-routing.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00021B"} -->
<!-- {"agent":"B004","command_id":"000000023047","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00021B-ClanStatusPaneConstructorCleanup-source-routing-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B004/00021B-ClanStatusPaneConstructorCleanup-source-routing.md","timestamp":"2026-08-13T02:36:38-04:00","uid":"00021B"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
