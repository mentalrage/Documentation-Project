# Agent A002 Notes

Lease report symlink:
`E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-A002\current_leases.md`

Do not edit `current_leases.md`; read it for live lease status before editing.

## 2026-06-06 active pending sync

Validator file-mode applies plus rescore completed for `000160`, `00016A`,
`00016E`, `00016U`, `00016V`, `00022P`, `00016W`, `00018P`, `00017G`,
`00017H`, `00017I`, `00016Y`, `000189`, `00017F`, `0000U4`, `0000UR`,
`0000UZ`, `0001CG`, `0002BX`, `0002BZ`, `0002C0`, `0002C1`, `0002C3`, and
`00014M`, `00019X`, `0001BN`, `0001BO`, `0001BR`, `0001CK`, `0001DJ`,
`0001DR`, `0001E1`, `0001EA`, `0001EE`, `0001EJ`, `0001EN`, `0001ES`,
`0001ET`, `00023M`, `0001FH`, `0001G5`, `0002VO`, `0001FL`, `0001FX`,
`00023U`, `0001GA`, `0001GB`, `0001GC`, `0001GD`, `0001GK`, `0001GL`,
`00023W`, `0001I5`, `0001GU`, `0001H6`, `00023Z`, `0001HS`, `000245`,
`0001JP`, `0001JS`, `0001KT`, `0001KW`, `0001LQ`, `0001LP`, `0001LS`,
`0001LU`, `0001LV`, and `0001LX` on 2026-06-06.
Manual `by-memory/-coverage-report.md` rows for
`0001CE`, `0001CG`, `0002BX`, `0002BZ`, `0002C0`, `0002C1`, `0002C3`,
`00017F`, `00017H`, `00017I`, `00014M`, `00019X`, `0001BN`, `0001BO`, and
`0001BR`, `0001CK`, `0001DJ`, `0001DR`, `0001E1`, `0001EA`, `0001EE`,
`0001EJ`, `0001EN`, `00023M`, `0001FH`, `0002VO`, `0001FL`, `0001FX`,
`0001GK`, `0001GL`, `0001GU`, `0001H6`, `00023Z`, `0001HS`, `000245`,
`0001JP`, `0001JS`, `0001KT`, and `0001KW`
have been applied.

When an approved new-file/stub workflow exists, create/register
`by-memory/0x004dc7e0-0x004dca14.RidingImageLibDrawRidingFrameRawHelper.md`
for the IDA-missed raw helper classified in RidingImageLib docs (suggested
score `78/82`, reconstructable, no autogen parent), then add a coverage child
row under `00017F`. Keep the parent `00017F` summary at `78%` unless new
evidence changes the score.
Current blocker: `leaser.py` rejects leases for nonexistent files, so this needs
an approved new-file/stub workflow before A002 can create the exact child page.

Promote `0000U4` and `0000UR` from by-item to exact by-memory pages later when
the same new-file/stub workflow is available for registration plus manual
coverage rows.

## Skipped Target Rechecks / Follow-Ups

- `000168`, `000169`, and `00016T` were rechecked after prior lease skips;
  their current docs/report rows no longer look like the stale low-completion
  stats. Recheck generated stats before spending more time there.
- `0001E6` `PaletteLib` looked like a stale low-completion target with likely
  by-file parent attachment/score cleanup available, but A005 held the target on
  2026-06-06. Recheck current stats/leases before returning to it.
- `0001EC` `PanelPane` looked ready for the same stale memory-page
  score/parent/coverage cleanup pattern, but A001 held the target on
  2026-06-06. Recheck current stats/leases before returning to it.
- Parcel notification low-score pages were being actively split by others:
  A005 held `0001EG`, `0001EI`, and `0001EO`; A008 held `0001EK` and
  `0001EP` on 2026-06-06. Recheck current stats/leases before returning to
  that cluster.
- Exchange follow-ups remain useful: split raw exchange code near `0x004adb10`
  and identify helper `0x004b0b50-0x004b0b5b`. `00014M` was renamed to exact
  half-open `0x004ada90-0x004adb02` and ExchangeDialog validation/reference
  refresh was run on 2026-06-06.
- Raw GrafPort helper candidates still need split/review near `0x004b94f0`,
  `0x004b9550`, `0x004b9770`, `0x004b99c0`, `0x004bb260`, and `0x004bb5b0`.

## Next useful work

Re-read `current_leases.md`, then continue the mixed-source queue, especially
Exchange exact-range/code-split follow-ups or the next current low-completion
by-memory target. Return to Riding/raw by-item promotions only after a
new-file/stub workflow is available.

## Pending Locked Report Updates
