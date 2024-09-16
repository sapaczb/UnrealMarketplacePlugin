//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once

#include "CoreMinimal.h"
#include "Core/PlayFabError.h"
#include "Core/PlayFabProfilesDataModels.h"
#include "Core/PlayFabSettings.h"
#include "PlayFabAPISettings.h"
#include "Interfaces/IHttpRequest.h"
#include "Interfaces/IHttpResponse.h"

namespace PlayFab
{
    /**
     * Main interface for PlayFab Sdk, specifically all Profiles APIs
     */
    class PLAYFABCPP_API UPlayFabProfilesInstanceAPI
    {
    public:
        DECLARE_DELEGATE_OneParam(FGetGlobalPolicyDelegate, const ProfilesModels::FGetGlobalPolicyResponse&);
        DECLARE_DELEGATE_OneParam(FGetProfileDelegate, const ProfilesModels::FGetEntityProfileResponse&);
        DECLARE_DELEGATE_OneParam(FGetProfilesDelegate, const ProfilesModels::FGetEntityProfilesResponse&);
        DECLARE_DELEGATE_OneParam(FGetTitlePlayersFromMasterPlayerAccountIdsDelegate, const ProfilesModels::FGetTitlePlayersFromMasterPlayerAccountIdsResponse&);
        DECLARE_DELEGATE_OneParam(FGetTitlePlayersFromXboxLiveIDsDelegate, const ProfilesModels::FGetTitlePlayersFromProviderIDsResponse&);
        DECLARE_DELEGATE_OneParam(FSetDisplayNameDelegate, const ProfilesModels::FSetDisplayNameResponse&);
        DECLARE_DELEGATE_OneParam(FSetGlobalPolicyDelegate, const ProfilesModels::FSetGlobalPolicyResponse&);
        DECLARE_DELEGATE_OneParam(FSetProfileLanguageDelegate, const ProfilesModels::FSetProfileLanguageResponse&);
        DECLARE_DELEGATE_OneParam(FSetProfilePolicyDelegate, const ProfilesModels::FSetEntityProfilePolicyResponse&);


    private:
        TSharedPtr<UPlayFabAPISettings> settings;
        TSharedPtr<UPlayFabAuthenticationContext> authContext;
    
    public:
        UPlayFabProfilesInstanceAPI();
        explicit UPlayFabProfilesInstanceAPI(TSharedPtr<UPlayFabAPISettings> apiSettings);
        explicit UPlayFabProfilesInstanceAPI(TSharedPtr<UPlayFabAuthenticationContext> authenticationContext);
        UPlayFabProfilesInstanceAPI(TSharedPtr<UPlayFabAPISettings> apiSettings, TSharedPtr<UPlayFabAuthenticationContext> authenticationContext);
        ~UPlayFabProfilesInstanceAPI();
        UPlayFabProfilesInstanceAPI(const UPlayFabProfilesInstanceAPI& source) = delete; // disable copy
        UPlayFabProfilesInstanceAPI(UPlayFabProfilesInstanceAPI&&) = delete; // disable move
        UPlayFabProfilesInstanceAPI& operator=(const UPlayFabProfilesInstanceAPI& source) = delete; // disable assignment
        UPlayFabProfilesInstanceAPI& operator=(UPlayFabProfilesInstanceAPI&& other) = delete; // disable move assignment

        int GetPendingCalls() const;
        TSharedPtr<UPlayFabAPISettings> GetSettings() const;
        void SetSettings(TSharedPtr<UPlayFabAPISettings> apiSettings);
        TSharedPtr<UPlayFabAuthenticationContext> GetAuthenticationContext() const;
        void SetAuthenticationContext(TSharedPtr<UPlayFabAuthenticationContext> authenticationContext);
        void ForgetAllCredentials();

    private:
        TSharedPtr<UPlayFabAuthenticationContext> GetOrCreateAuthenticationContext();
    
    public:


        // ------------ Generated API calls
        /**
         * Gets the global title access policy
         * Retrieves the title access policy that is used before the profile's policy is inspected during a request. If never customized this will return the default starter policy built by PlayFab.
         */
        bool GetGlobalPolicy(ProfilesModels::FGetGlobalPolicyRequest& request, const FGetGlobalPolicyDelegate& SuccessDelegate = FGetGlobalPolicyDelegate(), const FPlayFabErrorDelegate& ErrorDelegate = FPlayFabErrorDelegate());
        /**
         * Retrieves the entity's profile.
         * Given an entity type and entity identifier will retrieve the profile from the entity store. If the profile being retrieved is the caller's, then the read operation is consistent, if not it is an inconsistent read. An inconsistent read means that we do not guarantee all committed writes have occurred before reading the profile, allowing for a stale read. If consistency is important the Version Number on the result can be used to compare which version of the profile any reader has.
         */
        bool GetProfile(ProfilesModels::FGetEntityProfileRequest& request, const FGetProfileDelegate& SuccessDelegate = FGetProfileDelegate(), const FPlayFabErrorDelegate& ErrorDelegate = FPlayFabErrorDelegate());
        /**
         * Retrieves the entity's profile.
         * Given a set of entity types and entity identifiers will retrieve all readable profiles properties for the caller. Profiles that the caller is not allowed to read will silently not be included in the results.
         */
        bool GetProfiles(ProfilesModels::FGetEntityProfilesRequest& request, const FGetProfilesDelegate& SuccessDelegate = FGetProfilesDelegate(), const FPlayFabErrorDelegate& ErrorDelegate = FPlayFabErrorDelegate());
        /**
         * Retrieves the title player accounts associated with the given master player account.
         * Given a master player account id (PlayFab ID), returns all title player accounts associated with it.
         */
        bool GetTitlePlayersFromMasterPlayerAccountIds(ProfilesModels::FGetTitlePlayersFromMasterPlayerAccountIdsRequest& request, const FGetTitlePlayersFromMasterPlayerAccountIdsDelegate& SuccessDelegate = FGetTitlePlayersFromMasterPlayerAccountIdsDelegate(), const FPlayFabErrorDelegate& ErrorDelegate = FPlayFabErrorDelegate());
        /**
         * Retrieves the title player accounts associated with the given XUIDs.
         * Given a collection of Xbox IDs (XUIDs), returns all title player accounts.
         */
        bool GetTitlePlayersFromXboxLiveIDs(ProfilesModels::FGetTitlePlayersFromXboxLiveIDsRequest& request, const FGetTitlePlayersFromXboxLiveIDsDelegate& SuccessDelegate = FGetTitlePlayersFromXboxLiveIDsDelegate(), const FPlayFabErrorDelegate& ErrorDelegate = FPlayFabErrorDelegate());
        /**
         * Update the display name of the entity
         * Given an entity profile, will update its display name to the one passed in if the profile's version is equal to the specified value
         */
        bool SetDisplayName(ProfilesModels::FSetDisplayNameRequest& request, const FSetDisplayNameDelegate& SuccessDelegate = FSetDisplayNameDelegate(), const FPlayFabErrorDelegate& ErrorDelegate = FPlayFabErrorDelegate());
        /**
         * Sets the global title access policy
         * Updates the title access policy that is used before the profile's policy is inspected during a request. Policies are compiled and cached for several minutes so an update here may not be reflected in behavior for a short time.
         */
        bool SetGlobalPolicy(ProfilesModels::FSetGlobalPolicyRequest& request, const FSetGlobalPolicyDelegate& SuccessDelegate = FSetGlobalPolicyDelegate(), const FPlayFabErrorDelegate& ErrorDelegate = FPlayFabErrorDelegate());
        /**
         * Updates the entity's language. The precedence hierarchy for communication to the player is Title Player Account
         * language, Master Player Account language, and then title default language if the first two aren't set or supported.
         * Given an entity profile, will update its language to the one passed in if the profile's version is equal to the one passed in.
         */
        bool SetProfileLanguage(ProfilesModels::FSetProfileLanguageRequest& request, const FSetProfileLanguageDelegate& SuccessDelegate = FSetProfileLanguageDelegate(), const FPlayFabErrorDelegate& ErrorDelegate = FPlayFabErrorDelegate());
        /**
         * Sets the profiles access policy
         * This will set the access policy statements on the given entity profile. This is not additive, any existing statements will be replaced with the statements in this request.
         */
        bool SetProfilePolicy(ProfilesModels::FSetEntityProfilePolicyRequest& request, const FSetProfilePolicyDelegate& SuccessDelegate = FSetProfilePolicyDelegate(), const FPlayFabErrorDelegate& ErrorDelegate = FPlayFabErrorDelegate());

    private:
        // ------------ Generated result handlers
        void OnGetGlobalPolicyResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FGetGlobalPolicyDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate);
        void OnGetProfileResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FGetProfileDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate);
        void OnGetProfilesResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FGetProfilesDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate);
        void OnGetTitlePlayersFromMasterPlayerAccountIdsResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FGetTitlePlayersFromMasterPlayerAccountIdsDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate);
        void OnGetTitlePlayersFromXboxLiveIDsResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FGetTitlePlayersFromXboxLiveIDsDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate);
        void OnSetDisplayNameResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FSetDisplayNameDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate);
        void OnSetGlobalPolicyResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FSetGlobalPolicyDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate);
        void OnSetProfileLanguageResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FSetProfileLanguageDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate);
        void OnSetProfilePolicyResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FSetProfilePolicyDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate);

    };
};
