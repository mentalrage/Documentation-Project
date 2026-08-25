** TARGET-REPORT-UID:0001Y2 **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
## Finalized Report / Current Recommendation

- Target: [UID:0001Y2] `by-type/by-vtable/MailDialogVtableFamily.md`.
- Current recommendation: keep `MailDialogVtableFamily` as a reconstructable split inventory/container with blank `AUTOGEN_PARENT_UID`; use exact owner-specific child pages for assignment.
- Recommended status/classification: `reviewed-85-ownership-split`.
- Confidence: high, `88/91` for the master inventory after split. The binary table bases, RTTI/COL pointers, xrefs, and boundaries are high-confidence; the only remaining uncertainty is the final original-source split for the mail-only alert wrapper classes.
- Concrete next action for A-agents/supervisor: accept the split and use [UID:000321] `MailDialogCoreVtables` under [UID:0000KZ] `MailDialogs`, and [UID:000322] `MailAlertCompanionVtables` under [UID:0000HW] `BulletinReplyAlerts`. Do not assign [UID:0001Y2] itself to one parent.
- Report status: final for B001-009; no active blocker.
- Lease/collision note: temporary lease override was active; no leases were created or released. I saw no collision risk while editing.

## Supporting Research

### Split Outcome

The target is not a single direct-owner type page. It is a valid mixed vtable-family inventory whose contents split into two owner-specific children:

| Page | Before | After | Parent decision |
| --- | --- | --- | --- |
| [UID:0001Y2] `MailDialogVtableFamily.md` | `85/88`, blank parent, ownership unknown | `88/91`, blank parent, `reviewed-85-ownership-split` | Parent stays blank because it spans two direct owners. |
| [UID:000321] `MailDialogCoreVtables.md` | missing exact child page | created, `87/91` | Assigned to [UID:0000KZ] `MailDialogs` (`86/85`). |
| [UID:000322] `MailAlertCompanionVtables.md` | missing exact child page | created, `86/89` | Assigned to [UID:0000HW] `BulletinReplyAlerts` (`85/86`). |

This satisfies the split-first workflow: exact child pages now exist for the reconstructable subfamilies, both children clear `85/85`, and both selected direct parents clear `85/85`.

### Binary Evidence

B001-009 live IDA MCP `py_eval` was run on 2026-06-10 against IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, input `NexusTK.exe`, MD5 `4247e04e20b65d6414c7238aa8ff5515`.

Core `MailDialogs` vtables:

| Class | Vtable bases | Store evidence |
| --- | --- | --- |
| `MailListDialog` | `0x00614238`, `0x0061429c`, `0x006142cc` | Constructor stores at `0x0047916d`, `0x00479173`, `0x0047917d` inside `0x00479110-0x00479d2b`. |
| `MailListPane` | `0x006142d8`, `0x00614360`, `0x00614390` | Constructor stores at `0x0047a8d1`, `0x0047a8d7`, `0x0047a8e1` inside `0x0047a8a0-0x0047a8f9`. |
| `MailDialog` | `0x0061439c`, `0x00614400`, `0x00614430` | Constructor stores at `0x0047b287`, `0x0047b28d`, `0x0047b297` inside `0x0047b220-0x0047c405`. |
| `NewMailDialog` | `0x0061443c`, `0x006144a0`, `0x006144d0` | Constructor stores at `0x0047d0a1`, `0x0047d0a7`, `0x0047d0b1` inside `0x0047d050-0x0047d7c1`. |

Mail alert companion vtables:

| Class | Vtable bases | Store evidence |
| --- | --- | --- |
| `MailTransferReplyAlert` | `0x006144dc`, `0x00614544`, `0x00614574` | Stores at `0x0047d90d/0x0047d913/0x0047d91d`, `0x0047db2b/0x0047db31/0x0047db3b`, `0x0047dc61/0x0047dc67/0x0047dc71`, and raw constructor-shaped stores at `0x0047e067/0x0047e06d/0x0047e077`. |
| `ConfirmDeleteMailAlert` | `0x006146c8`, `0x00614730`, `0x00614760` | Stores at `0x0047a17b/0x0047a181/0x0047a18b`, `0x0047a2e4/0x0047a2ea/0x0047a2f4`, `0x0047c6c5/0x0047c6cb/0x0047c6d5`, `0x0047c9b4/0x0047c9ba/0x0047c9c4`, and raw constructor-shaped stores at `0x0047e4e7/0x0047e4ed/0x0047e4f7`. |
| `MailDeleteReplyAlert` | `0x0061476c`, `0x006147d4`, `0x00614804` | Stores at `0x0047a4bf/0x0047a4c5/0x0047a4cf`, `0x0047a84d/0x0047a853/0x0047a85d`, `0x0047caf7/0x0047cafd/0x0047cb07`, `0x0047cc2d/0x0047cc33/0x0047cc3d`, raw constructor stores at `0x0047e6c7/0x0047e6cd/0x0047e6d7`, destructor stores at `0x0047e6f0/0x0047e6f6/0x0047e700`, and scalar-destructor stores at `0x0047eb96/0x0047eb9c/0x0047eba6`. |

Boundary facts:

- `MailDialogCoreVtables` ends at the `NewMailDialog` tertiary view `0x006144d0`; the successor is `MailTransferReplyAlert` at `0x006144dc`.
- `MailTransferReplyAlert` tertiary `0x00614574` ends before shared `ConfirmDeleteAlert` vtables at `0x00614580`, `0x006145e8`, and `0x00614618`.
- Shared `DeleteReplyAlert` vtables at `0x00614624`, `0x0061468c`, and `0x006146bc` sit between the mail-transfer and confirm-delete-mail tables and are intentionally excluded from the mail-specific alert child.
- `ConfirmDeleteMailAlert` resumes at `0x006146c8`; `MailDeleteReplyAlert` ends at `0x0061480c`.
- `0x0061480c` begins non-vtable string/resource data (`dword_61480C`, `aGbbs01Pal` at `0x00614818`).

### Documentation Evidence and Caveats

Existing docs were treated as prior hypotheses, not proof:

- [UID:0000KZ] `MailDialogs` already documented the core mail list/read/compose code range and clears `86/85`. IDA confirms the core vtable stores are in that mail dialog constructor cluster.
- [UID:0000HW] `BulletinReplyAlerts` already documented the shared board/mail reply-delete alert wrapper bucket and clears `85/86`. IDA confirms the alert companion vtables are wrapper classes interleaved with shared `ConfirmDeleteAlert` and `DeleteReplyAlert` tables.
- [UID:0000ZO] `0x00479110-0x0047ec2b.MailDialogs` remains useful as a broad executable-code aggregate, but it is broader than the exact vtable ownership split.
- [UID:0000ZM] `0x00478fe0-0x0047ec6b.BulletinMailAlertCompanions` remains a mixed overlap/index map, not the direct parent for this type page.
- [UID:00024W] `0x00613ab0-0x00614cd0.BoardMailReadOnlyData` is a broad `.rdata` aggregate and not a source owner.

The main uncertainty is source-file placement for the mail-only alert wrappers. The vtable stores are mail-context stores, so `MailDialogs` is a serious alternate. The current best inference keeps those wrappers with `BulletinReplyAlerts` because the shared board/mail alert-wrapper model already owns the sibling classes/singletons, the shared alert tables are physically interleaved, and the parent page clears the gate.

### Candidate Ranking

1. Split into exact children: selected. This matches the binary clusters and lets each child attach to a gate-cleared direct source owner.
2. Assign whole family to `MailDialogs`: rejected for the master. It is the best forced single-owner alternate, but it would absorb the alert-wrapper bucket and ignore the shared alert gap.
3. Assign whole family to `BulletinReplyAlerts`: rejected for the master. It fits the alert companion child but not the four core mail dialog/list/compose classes.
4. Assign whole family to `BoardMailReadOnlyData`: rejected. It is a mixed `.rdata` range, not a source owner.
5. Create a new `MailAndReplyAlerts.cpp` owner: rejected. The needed scope is not a new broad file; the existing `MailDialogs` and `BulletinReplyAlerts` owners already clear the gate and match the two subclusters.

### Files Changed

- Created `by-type/by-vtable/MailDialogCoreVtables.md` as [UID:000321], `87/91`, parent [UID:0000KZ].
- Created `by-type/by-vtable/MailAlertCompanionVtables.md` as [UID:000322], `86/89`, parent [UID:0000HW].
- Updated `by-type/by-vtable/MailDialogVtableFamily.md` from `85/88` to `88/91` and reclassified it as a split inventory with blank parent.
- Updated `by-type/by-vtable/-coverage-report.md` rows and count for the two new child pages and the revised master row.
- Updated `by-file/MailDialogs.md` and `by-file/BulletinReplyAlerts.md` with exact child cross-references and B001-009 evidence notes, without changing their scores.
- Updated `by-file/-coverage-report.md` rows for [UID:0000KZ] and [UID:0000HW].

### Validation

Targeted validator commands run with `--apply`; each returned `ok: 1`:

_Executable command block removed from the research report; preserved in [0001Y2-MailDialogVtableFamily-removed.md](0001Y2-MailDialogVtableFamily-removed.md)._

Generated type coverage now shows [UID:000321] assigned to `0000KZ`, [UID:000322] assigned to `0000HW`, and [UID:0001Y2] unassigned by design.

### Follow-Up

- A-agents should use [UID:000321] and [UID:000322] as the direct vtable children for future code/source reconstruction.
- If future source evidence proves `MailTransferReplyAlert`, `ConfirmDeleteMailAlert`, and `MailDeleteReplyAlert` were private classes inside `MailDialogs.cpp`, reconsider only [UID:000322]; do not collapse the master family back into a single parent without resolving the shared alert interleave.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/0001Y2-MailDialogVtableFamily.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:20","uid":"0001Y2"} -->
<!-- {"agent":"B001","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001Y2-MailDialogVtableFamily-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B001/0001Y2-MailDialogVtableFamily.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001Y2"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
