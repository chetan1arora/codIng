
.editTeamIcons{
  display:flex;
  flex-direction: row-reverse;
  position: relative;
  left:38rem;
  top:2.8rem;
  max-width:12rem;
  z-index: 1;
}

action-icons for all icons

  <div
                  class="editTeamIcons"
                  ng-if="!isEditUsers"
                  ng-hide="addUserToCompany"
                >
                  <i
                    class="material-icons action-icons"
                    id="addPersonBtn1"
                    data-toggle="modal"
                    data-target="#addPersonModal"
                    ng-click="personAdd()"
                  >
                    person_add
                  </i>
                  <i
                    class="material-icons action-icons"
                    id="addPersonBtn"
                    data-toggle="modal"
                    ng-if="showEditDeleteBtn"
                    data-target="#deleteConfirmationDialog"
                  >
                    delete
                  </i>
                  <i
                    class="material-icons action-icons"
                    id="addPersonBtn"
                    data-toggle="modal"
                    ng-if="showEditDeleteBtn"
                    ng-click="switchEditMode(true)"
                  >
                    edit
                  </i>
                </div>