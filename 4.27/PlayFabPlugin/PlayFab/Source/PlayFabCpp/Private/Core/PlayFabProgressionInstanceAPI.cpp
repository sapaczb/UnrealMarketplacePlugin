//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "Core/PlayFabProgressionInstanceAPI.h"
#include "Core/PlayFabSettings.h"
#include "Core/PlayFabResultHandler.h"
#include "PlayFab.h"

using namespace PlayFab;
using namespace PlayFab::ProgressionModels;

UPlayFabProgressionInstanceAPI::UPlayFabProgressionInstanceAPI()
{
}

UPlayFabProgressionInstanceAPI::UPlayFabProgressionInstanceAPI(TSharedPtr<UPlayFabAPISettings> apiSettings)
{
    this->settings = MoveTemp(apiSettings);
}

UPlayFabProgressionInstanceAPI::UPlayFabProgressionInstanceAPI(TSharedPtr<UPlayFabAuthenticationContext> authenticationContext)
{
    this->authContext = MoveTemp(authenticationContext);
}

UPlayFabProgressionInstanceAPI::UPlayFabProgressionInstanceAPI(TSharedPtr<UPlayFabAPISettings> apiSettings, TSharedPtr<UPlayFabAuthenticationContext> authenticationContext)
{
    this->settings = MoveTemp(apiSettings);
    this->authContext = MoveTemp(authenticationContext);
}

UPlayFabProgressionInstanceAPI::~UPlayFabProgressionInstanceAPI()
{
}

TSharedPtr<UPlayFabAPISettings> UPlayFabProgressionInstanceAPI::GetSettings() const
{
    return this->settings;
}

int UPlayFabProgressionInstanceAPI::GetPendingCalls() const
{
    return PlayFabRequestHandler::GetPendingCalls();
}

void UPlayFabProgressionInstanceAPI::SetSettings(TSharedPtr<UPlayFabAPISettings> apiSettings)
{
    this->settings = MoveTemp(apiSettings);
}

TSharedPtr<UPlayFabAuthenticationContext> UPlayFabProgressionInstanceAPI::GetAuthenticationContext() const
{
    return this->authContext;
}

void UPlayFabProgressionInstanceAPI::SetAuthenticationContext(TSharedPtr<UPlayFabAuthenticationContext> authenticationContext)
{
    this->authContext = MoveTemp(authenticationContext);
}

void UPlayFabProgressionInstanceAPI::ForgetAllCredentials()
{
    if (!this->authContext.IsValid())
        return;

    this->authContext->ForgetAllCredentials();
}

TSharedPtr<UPlayFabAuthenticationContext> UPlayFabProgressionInstanceAPI::GetOrCreateAuthenticationContext()
{
    if (!this->authContext.IsValid())
        this->authContext = MakeSharedUObject<UPlayFabAuthenticationContext>();

    return this->authContext;
}

bool UPlayFabProgressionInstanceAPI::CreateLeaderboardDefinition(
    ProgressionModels::FCreateLeaderboardDefinitionRequest& request,
    const FCreateLeaderboardDefinitionDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    TSharedPtr<UPlayFabAuthenticationContext> context = request.AuthenticationContext.IsValid() ? request.AuthenticationContext : GetOrCreateAuthenticationContext();
    if (context->GetEntityToken().Len() == 0) {
        UE_LOG(LogPlayFabCpp, Error, TEXT("You must call GetEntityToken API Method before calling this function."));
    }


    auto HttpRequest = PlayFabRequestHandler::SendRequest(this->settings, TEXT("/Leaderboard/CreateLeaderboardDefinition"), request.toJSONString(), TEXT("X-EntityToken"), context->GetEntityToken());
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabProgressionInstanceAPI::OnCreateLeaderboardDefinitionResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabProgressionInstanceAPI::OnCreateLeaderboardDefinitionResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FCreateLeaderboardDefinitionDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    ProgressionModels::FEmptyResponse outResult;
    FPlayFabCppError errorResult;
    if (PlayFabRequestHandler::DecodeRequest(HttpRequest, HttpResponse, bSucceeded, outResult, errorResult))
    {
        SuccessDelegate.ExecuteIfBound(outResult);
    }
    else
    {
        ErrorDelegate.ExecuteIfBound(errorResult);
    }
}

bool UPlayFabProgressionInstanceAPI::CreateStatisticDefinition(
    ProgressionModels::FCreateStatisticDefinitionRequest& request,
    const FCreateStatisticDefinitionDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    TSharedPtr<UPlayFabAuthenticationContext> context = request.AuthenticationContext.IsValid() ? request.AuthenticationContext : GetOrCreateAuthenticationContext();
    if (context->GetEntityToken().Len() == 0) {
        UE_LOG(LogPlayFabCpp, Error, TEXT("You must call GetEntityToken API Method before calling this function."));
    }


    auto HttpRequest = PlayFabRequestHandler::SendRequest(this->settings, TEXT("/Statistic/CreateStatisticDefinition"), request.toJSONString(), TEXT("X-EntityToken"), context->GetEntityToken());
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabProgressionInstanceAPI::OnCreateStatisticDefinitionResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabProgressionInstanceAPI::OnCreateStatisticDefinitionResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FCreateStatisticDefinitionDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    ProgressionModels::FEmptyResponse outResult;
    FPlayFabCppError errorResult;
    if (PlayFabRequestHandler::DecodeRequest(HttpRequest, HttpResponse, bSucceeded, outResult, errorResult))
    {
        SuccessDelegate.ExecuteIfBound(outResult);
    }
    else
    {
        ErrorDelegate.ExecuteIfBound(errorResult);
    }
}

bool UPlayFabProgressionInstanceAPI::DeleteLeaderboardDefinition(
    ProgressionModels::FDeleteLeaderboardDefinitionRequest& request,
    const FDeleteLeaderboardDefinitionDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    TSharedPtr<UPlayFabAuthenticationContext> context = request.AuthenticationContext.IsValid() ? request.AuthenticationContext : GetOrCreateAuthenticationContext();
    if (context->GetEntityToken().Len() == 0) {
        UE_LOG(LogPlayFabCpp, Error, TEXT("You must call GetEntityToken API Method before calling this function."));
    }


    auto HttpRequest = PlayFabRequestHandler::SendRequest(this->settings, TEXT("/Leaderboard/DeleteLeaderboardDefinition"), request.toJSONString(), TEXT("X-EntityToken"), context->GetEntityToken());
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabProgressionInstanceAPI::OnDeleteLeaderboardDefinitionResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabProgressionInstanceAPI::OnDeleteLeaderboardDefinitionResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FDeleteLeaderboardDefinitionDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    ProgressionModels::FEmptyResponse outResult;
    FPlayFabCppError errorResult;
    if (PlayFabRequestHandler::DecodeRequest(HttpRequest, HttpResponse, bSucceeded, outResult, errorResult))
    {
        SuccessDelegate.ExecuteIfBound(outResult);
    }
    else
    {
        ErrorDelegate.ExecuteIfBound(errorResult);
    }
}

bool UPlayFabProgressionInstanceAPI::DeleteLeaderboardEntries(
    ProgressionModels::FDeleteLeaderboardEntriesRequest& request,
    const FDeleteLeaderboardEntriesDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    TSharedPtr<UPlayFabAuthenticationContext> context = request.AuthenticationContext.IsValid() ? request.AuthenticationContext : GetOrCreateAuthenticationContext();
    if (context->GetEntityToken().Len() == 0) {
        UE_LOG(LogPlayFabCpp, Error, TEXT("You must call GetEntityToken API Method before calling this function."));
    }


    auto HttpRequest = PlayFabRequestHandler::SendRequest(this->settings, TEXT("/Leaderboard/DeleteLeaderboardEntries"), request.toJSONString(), TEXT("X-EntityToken"), context->GetEntityToken());
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabProgressionInstanceAPI::OnDeleteLeaderboardEntriesResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabProgressionInstanceAPI::OnDeleteLeaderboardEntriesResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FDeleteLeaderboardEntriesDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    ProgressionModels::FEmptyResponse outResult;
    FPlayFabCppError errorResult;
    if (PlayFabRequestHandler::DecodeRequest(HttpRequest, HttpResponse, bSucceeded, outResult, errorResult))
    {
        SuccessDelegate.ExecuteIfBound(outResult);
    }
    else
    {
        ErrorDelegate.ExecuteIfBound(errorResult);
    }
}

bool UPlayFabProgressionInstanceAPI::DeleteStatisticDefinition(
    ProgressionModels::FDeleteStatisticDefinitionRequest& request,
    const FDeleteStatisticDefinitionDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    TSharedPtr<UPlayFabAuthenticationContext> context = request.AuthenticationContext.IsValid() ? request.AuthenticationContext : GetOrCreateAuthenticationContext();
    if (context->GetEntityToken().Len() == 0) {
        UE_LOG(LogPlayFabCpp, Error, TEXT("You must call GetEntityToken API Method before calling this function."));
    }


    auto HttpRequest = PlayFabRequestHandler::SendRequest(this->settings, TEXT("/Statistic/DeleteStatisticDefinition"), request.toJSONString(), TEXT("X-EntityToken"), context->GetEntityToken());
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabProgressionInstanceAPI::OnDeleteStatisticDefinitionResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabProgressionInstanceAPI::OnDeleteStatisticDefinitionResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FDeleteStatisticDefinitionDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    ProgressionModels::FEmptyResponse outResult;
    FPlayFabCppError errorResult;
    if (PlayFabRequestHandler::DecodeRequest(HttpRequest, HttpResponse, bSucceeded, outResult, errorResult))
    {
        SuccessDelegate.ExecuteIfBound(outResult);
    }
    else
    {
        ErrorDelegate.ExecuteIfBound(errorResult);
    }
}

bool UPlayFabProgressionInstanceAPI::DeleteStatistics(
    ProgressionModels::FDeleteStatisticsRequest& request,
    const FDeleteStatisticsDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    TSharedPtr<UPlayFabAuthenticationContext> context = request.AuthenticationContext.IsValid() ? request.AuthenticationContext : GetOrCreateAuthenticationContext();
    if (context->GetEntityToken().Len() == 0) {
        UE_LOG(LogPlayFabCpp, Error, TEXT("You must call GetEntityToken API Method before calling this function."));
    }


    auto HttpRequest = PlayFabRequestHandler::SendRequest(this->settings, TEXT("/Statistic/DeleteStatistics"), request.toJSONString(), TEXT("X-EntityToken"), context->GetEntityToken());
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabProgressionInstanceAPI::OnDeleteStatisticsResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabProgressionInstanceAPI::OnDeleteStatisticsResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FDeleteStatisticsDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    ProgressionModels::FDeleteStatisticsResponse outResult;
    FPlayFabCppError errorResult;
    if (PlayFabRequestHandler::DecodeRequest(HttpRequest, HttpResponse, bSucceeded, outResult, errorResult))
    {
        SuccessDelegate.ExecuteIfBound(outResult);
    }
    else
    {
        ErrorDelegate.ExecuteIfBound(errorResult);
    }
}

bool UPlayFabProgressionInstanceAPI::GetFriendLeaderboardForEntity(
    ProgressionModels::FGetFriendLeaderboardForEntityRequest& request,
    const FGetFriendLeaderboardForEntityDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    TSharedPtr<UPlayFabAuthenticationContext> context = request.AuthenticationContext.IsValid() ? request.AuthenticationContext : GetOrCreateAuthenticationContext();
    if (context->GetEntityToken().Len() == 0) {
        UE_LOG(LogPlayFabCpp, Error, TEXT("You must call GetEntityToken API Method before calling this function."));
    }


    auto HttpRequest = PlayFabRequestHandler::SendRequest(this->settings, TEXT("/Leaderboard/GetFriendLeaderboardForEntity"), request.toJSONString(), TEXT("X-EntityToken"), context->GetEntityToken());
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabProgressionInstanceAPI::OnGetFriendLeaderboardForEntityResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabProgressionInstanceAPI::OnGetFriendLeaderboardForEntityResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FGetFriendLeaderboardForEntityDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    ProgressionModels::FGetEntityLeaderboardResponse outResult;
    FPlayFabCppError errorResult;
    if (PlayFabRequestHandler::DecodeRequest(HttpRequest, HttpResponse, bSucceeded, outResult, errorResult))
    {
        SuccessDelegate.ExecuteIfBound(outResult);
    }
    else
    {
        ErrorDelegate.ExecuteIfBound(errorResult);
    }
}

bool UPlayFabProgressionInstanceAPI::GetLeaderboard(
    ProgressionModels::FGetEntityLeaderboardRequest& request,
    const FGetLeaderboardDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    TSharedPtr<UPlayFabAuthenticationContext> context = request.AuthenticationContext.IsValid() ? request.AuthenticationContext : GetOrCreateAuthenticationContext();
    if (context->GetEntityToken().Len() == 0) {
        UE_LOG(LogPlayFabCpp, Error, TEXT("You must call GetEntityToken API Method before calling this function."));
    }


    auto HttpRequest = PlayFabRequestHandler::SendRequest(this->settings, TEXT("/Leaderboard/GetLeaderboard"), request.toJSONString(), TEXT("X-EntityToken"), context->GetEntityToken());
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabProgressionInstanceAPI::OnGetLeaderboardResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabProgressionInstanceAPI::OnGetLeaderboardResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FGetLeaderboardDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    ProgressionModels::FGetEntityLeaderboardResponse outResult;
    FPlayFabCppError errorResult;
    if (PlayFabRequestHandler::DecodeRequest(HttpRequest, HttpResponse, bSucceeded, outResult, errorResult))
    {
        SuccessDelegate.ExecuteIfBound(outResult);
    }
    else
    {
        ErrorDelegate.ExecuteIfBound(errorResult);
    }
}

bool UPlayFabProgressionInstanceAPI::GetLeaderboardAroundEntity(
    ProgressionModels::FGetLeaderboardAroundEntityRequest& request,
    const FGetLeaderboardAroundEntityDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    TSharedPtr<UPlayFabAuthenticationContext> context = request.AuthenticationContext.IsValid() ? request.AuthenticationContext : GetOrCreateAuthenticationContext();
    if (context->GetEntityToken().Len() == 0) {
        UE_LOG(LogPlayFabCpp, Error, TEXT("You must call GetEntityToken API Method before calling this function."));
    }


    auto HttpRequest = PlayFabRequestHandler::SendRequest(this->settings, TEXT("/Leaderboard/GetLeaderboardAroundEntity"), request.toJSONString(), TEXT("X-EntityToken"), context->GetEntityToken());
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabProgressionInstanceAPI::OnGetLeaderboardAroundEntityResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabProgressionInstanceAPI::OnGetLeaderboardAroundEntityResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FGetLeaderboardAroundEntityDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    ProgressionModels::FGetEntityLeaderboardResponse outResult;
    FPlayFabCppError errorResult;
    if (PlayFabRequestHandler::DecodeRequest(HttpRequest, HttpResponse, bSucceeded, outResult, errorResult))
    {
        SuccessDelegate.ExecuteIfBound(outResult);
    }
    else
    {
        ErrorDelegate.ExecuteIfBound(errorResult);
    }
}

bool UPlayFabProgressionInstanceAPI::GetLeaderboardDefinition(
    ProgressionModels::FGetLeaderboardDefinitionRequest& request,
    const FGetLeaderboardDefinitionDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    TSharedPtr<UPlayFabAuthenticationContext> context = request.AuthenticationContext.IsValid() ? request.AuthenticationContext : GetOrCreateAuthenticationContext();
    if (context->GetEntityToken().Len() == 0) {
        UE_LOG(LogPlayFabCpp, Error, TEXT("You must call GetEntityToken API Method before calling this function."));
    }


    auto HttpRequest = PlayFabRequestHandler::SendRequest(this->settings, TEXT("/Leaderboard/GetLeaderboardDefinition"), request.toJSONString(), TEXT("X-EntityToken"), context->GetEntityToken());
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabProgressionInstanceAPI::OnGetLeaderboardDefinitionResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabProgressionInstanceAPI::OnGetLeaderboardDefinitionResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FGetLeaderboardDefinitionDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    ProgressionModels::FGetLeaderboardDefinitionResponse outResult;
    FPlayFabCppError errorResult;
    if (PlayFabRequestHandler::DecodeRequest(HttpRequest, HttpResponse, bSucceeded, outResult, errorResult))
    {
        SuccessDelegate.ExecuteIfBound(outResult);
    }
    else
    {
        ErrorDelegate.ExecuteIfBound(errorResult);
    }
}

bool UPlayFabProgressionInstanceAPI::GetLeaderboardForEntities(
    ProgressionModels::FGetLeaderboardForEntitiesRequest& request,
    const FGetLeaderboardForEntitiesDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    TSharedPtr<UPlayFabAuthenticationContext> context = request.AuthenticationContext.IsValid() ? request.AuthenticationContext : GetOrCreateAuthenticationContext();
    if (context->GetEntityToken().Len() == 0) {
        UE_LOG(LogPlayFabCpp, Error, TEXT("You must call GetEntityToken API Method before calling this function."));
    }


    auto HttpRequest = PlayFabRequestHandler::SendRequest(this->settings, TEXT("/Leaderboard/GetLeaderboardForEntities"), request.toJSONString(), TEXT("X-EntityToken"), context->GetEntityToken());
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabProgressionInstanceAPI::OnGetLeaderboardForEntitiesResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabProgressionInstanceAPI::OnGetLeaderboardForEntitiesResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FGetLeaderboardForEntitiesDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    ProgressionModels::FGetEntityLeaderboardResponse outResult;
    FPlayFabCppError errorResult;
    if (PlayFabRequestHandler::DecodeRequest(HttpRequest, HttpResponse, bSucceeded, outResult, errorResult))
    {
        SuccessDelegate.ExecuteIfBound(outResult);
    }
    else
    {
        ErrorDelegate.ExecuteIfBound(errorResult);
    }
}

bool UPlayFabProgressionInstanceAPI::GetStatisticDefinition(
    ProgressionModels::FGetStatisticDefinitionRequest& request,
    const FGetStatisticDefinitionDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    TSharedPtr<UPlayFabAuthenticationContext> context = request.AuthenticationContext.IsValid() ? request.AuthenticationContext : GetOrCreateAuthenticationContext();
    if (context->GetEntityToken().Len() == 0) {
        UE_LOG(LogPlayFabCpp, Error, TEXT("You must call GetEntityToken API Method before calling this function."));
    }


    auto HttpRequest = PlayFabRequestHandler::SendRequest(this->settings, TEXT("/Statistic/GetStatisticDefinition"), request.toJSONString(), TEXT("X-EntityToken"), context->GetEntityToken());
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabProgressionInstanceAPI::OnGetStatisticDefinitionResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabProgressionInstanceAPI::OnGetStatisticDefinitionResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FGetStatisticDefinitionDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    ProgressionModels::FGetStatisticDefinitionResponse outResult;
    FPlayFabCppError errorResult;
    if (PlayFabRequestHandler::DecodeRequest(HttpRequest, HttpResponse, bSucceeded, outResult, errorResult))
    {
        SuccessDelegate.ExecuteIfBound(outResult);
    }
    else
    {
        ErrorDelegate.ExecuteIfBound(errorResult);
    }
}

bool UPlayFabProgressionInstanceAPI::GetStatistics(
    ProgressionModels::FGetStatisticsRequest& request,
    const FGetStatisticsDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    TSharedPtr<UPlayFabAuthenticationContext> context = request.AuthenticationContext.IsValid() ? request.AuthenticationContext : GetOrCreateAuthenticationContext();
    if (context->GetEntityToken().Len() == 0) {
        UE_LOG(LogPlayFabCpp, Error, TEXT("You must call GetEntityToken API Method before calling this function."));
    }


    auto HttpRequest = PlayFabRequestHandler::SendRequest(this->settings, TEXT("/Statistic/GetStatistics"), request.toJSONString(), TEXT("X-EntityToken"), context->GetEntityToken());
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabProgressionInstanceAPI::OnGetStatisticsResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabProgressionInstanceAPI::OnGetStatisticsResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FGetStatisticsDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    ProgressionModels::FGetStatisticsResponse outResult;
    FPlayFabCppError errorResult;
    if (PlayFabRequestHandler::DecodeRequest(HttpRequest, HttpResponse, bSucceeded, outResult, errorResult))
    {
        SuccessDelegate.ExecuteIfBound(outResult);
    }
    else
    {
        ErrorDelegate.ExecuteIfBound(errorResult);
    }
}

bool UPlayFabProgressionInstanceAPI::GetStatisticsForEntities(
    ProgressionModels::FGetStatisticsForEntitiesRequest& request,
    const FGetStatisticsForEntitiesDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    TSharedPtr<UPlayFabAuthenticationContext> context = request.AuthenticationContext.IsValid() ? request.AuthenticationContext : GetOrCreateAuthenticationContext();
    if (context->GetEntityToken().Len() == 0) {
        UE_LOG(LogPlayFabCpp, Error, TEXT("You must call GetEntityToken API Method before calling this function."));
    }


    auto HttpRequest = PlayFabRequestHandler::SendRequest(this->settings, TEXT("/Statistic/GetStatisticsForEntities"), request.toJSONString(), TEXT("X-EntityToken"), context->GetEntityToken());
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabProgressionInstanceAPI::OnGetStatisticsForEntitiesResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabProgressionInstanceAPI::OnGetStatisticsForEntitiesResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FGetStatisticsForEntitiesDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    ProgressionModels::FGetStatisticsForEntitiesResponse outResult;
    FPlayFabCppError errorResult;
    if (PlayFabRequestHandler::DecodeRequest(HttpRequest, HttpResponse, bSucceeded, outResult, errorResult))
    {
        SuccessDelegate.ExecuteIfBound(outResult);
    }
    else
    {
        ErrorDelegate.ExecuteIfBound(errorResult);
    }
}

bool UPlayFabProgressionInstanceAPI::IncrementLeaderboardVersion(
    ProgressionModels::FIncrementLeaderboardVersionRequest& request,
    const FIncrementLeaderboardVersionDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    TSharedPtr<UPlayFabAuthenticationContext> context = request.AuthenticationContext.IsValid() ? request.AuthenticationContext : GetOrCreateAuthenticationContext();
    if (context->GetEntityToken().Len() == 0) {
        UE_LOG(LogPlayFabCpp, Error, TEXT("You must call GetEntityToken API Method before calling this function."));
    }


    auto HttpRequest = PlayFabRequestHandler::SendRequest(this->settings, TEXT("/Leaderboard/IncrementLeaderboardVersion"), request.toJSONString(), TEXT("X-EntityToken"), context->GetEntityToken());
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabProgressionInstanceAPI::OnIncrementLeaderboardVersionResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabProgressionInstanceAPI::OnIncrementLeaderboardVersionResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FIncrementLeaderboardVersionDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    ProgressionModels::FIncrementLeaderboardVersionResponse outResult;
    FPlayFabCppError errorResult;
    if (PlayFabRequestHandler::DecodeRequest(HttpRequest, HttpResponse, bSucceeded, outResult, errorResult))
    {
        SuccessDelegate.ExecuteIfBound(outResult);
    }
    else
    {
        ErrorDelegate.ExecuteIfBound(errorResult);
    }
}

bool UPlayFabProgressionInstanceAPI::IncrementStatisticVersion(
    ProgressionModels::FIncrementStatisticVersionRequest& request,
    const FIncrementStatisticVersionDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    TSharedPtr<UPlayFabAuthenticationContext> context = request.AuthenticationContext.IsValid() ? request.AuthenticationContext : GetOrCreateAuthenticationContext();
    if (context->GetEntityToken().Len() == 0) {
        UE_LOG(LogPlayFabCpp, Error, TEXT("You must call GetEntityToken API Method before calling this function."));
    }


    auto HttpRequest = PlayFabRequestHandler::SendRequest(this->settings, TEXT("/Statistic/IncrementStatisticVersion"), request.toJSONString(), TEXT("X-EntityToken"), context->GetEntityToken());
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabProgressionInstanceAPI::OnIncrementStatisticVersionResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabProgressionInstanceAPI::OnIncrementStatisticVersionResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FIncrementStatisticVersionDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    ProgressionModels::FIncrementStatisticVersionResponse outResult;
    FPlayFabCppError errorResult;
    if (PlayFabRequestHandler::DecodeRequest(HttpRequest, HttpResponse, bSucceeded, outResult, errorResult))
    {
        SuccessDelegate.ExecuteIfBound(outResult);
    }
    else
    {
        ErrorDelegate.ExecuteIfBound(errorResult);
    }
}

bool UPlayFabProgressionInstanceAPI::ListLeaderboardDefinitions(
    ProgressionModels::FListLeaderboardDefinitionsRequest& request,
    const FListLeaderboardDefinitionsDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    TSharedPtr<UPlayFabAuthenticationContext> context = request.AuthenticationContext.IsValid() ? request.AuthenticationContext : GetOrCreateAuthenticationContext();
    if (context->GetEntityToken().Len() == 0) {
        UE_LOG(LogPlayFabCpp, Error, TEXT("You must call GetEntityToken API Method before calling this function."));
    }


    auto HttpRequest = PlayFabRequestHandler::SendRequest(this->settings, TEXT("/Leaderboard/ListLeaderboardDefinitions"), request.toJSONString(), TEXT("X-EntityToken"), context->GetEntityToken());
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabProgressionInstanceAPI::OnListLeaderboardDefinitionsResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabProgressionInstanceAPI::OnListLeaderboardDefinitionsResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FListLeaderboardDefinitionsDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    ProgressionModels::FListLeaderboardDefinitionsResponse outResult;
    FPlayFabCppError errorResult;
    if (PlayFabRequestHandler::DecodeRequest(HttpRequest, HttpResponse, bSucceeded, outResult, errorResult))
    {
        SuccessDelegate.ExecuteIfBound(outResult);
    }
    else
    {
        ErrorDelegate.ExecuteIfBound(errorResult);
    }
}

bool UPlayFabProgressionInstanceAPI::ListStatisticDefinitions(
    ProgressionModels::FListStatisticDefinitionsRequest& request,
    const FListStatisticDefinitionsDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    TSharedPtr<UPlayFabAuthenticationContext> context = request.AuthenticationContext.IsValid() ? request.AuthenticationContext : GetOrCreateAuthenticationContext();
    if (context->GetEntityToken().Len() == 0) {
        UE_LOG(LogPlayFabCpp, Error, TEXT("You must call GetEntityToken API Method before calling this function."));
    }


    auto HttpRequest = PlayFabRequestHandler::SendRequest(this->settings, TEXT("/Statistic/ListStatisticDefinitions"), request.toJSONString(), TEXT("X-EntityToken"), context->GetEntityToken());
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabProgressionInstanceAPI::OnListStatisticDefinitionsResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabProgressionInstanceAPI::OnListStatisticDefinitionsResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FListStatisticDefinitionsDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    ProgressionModels::FListStatisticDefinitionsResponse outResult;
    FPlayFabCppError errorResult;
    if (PlayFabRequestHandler::DecodeRequest(HttpRequest, HttpResponse, bSucceeded, outResult, errorResult))
    {
        SuccessDelegate.ExecuteIfBound(outResult);
    }
    else
    {
        ErrorDelegate.ExecuteIfBound(errorResult);
    }
}

bool UPlayFabProgressionInstanceAPI::UnlinkLeaderboardFromStatistic(
    ProgressionModels::FUnlinkLeaderboardFromStatisticRequest& request,
    const FUnlinkLeaderboardFromStatisticDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    TSharedPtr<UPlayFabAuthenticationContext> context = request.AuthenticationContext.IsValid() ? request.AuthenticationContext : GetOrCreateAuthenticationContext();
    if (context->GetEntityToken().Len() == 0) {
        UE_LOG(LogPlayFabCpp, Error, TEXT("You must call GetEntityToken API Method before calling this function."));
    }


    auto HttpRequest = PlayFabRequestHandler::SendRequest(this->settings, TEXT("/Leaderboard/UnlinkLeaderboardFromStatistic"), request.toJSONString(), TEXT("X-EntityToken"), context->GetEntityToken());
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabProgressionInstanceAPI::OnUnlinkLeaderboardFromStatisticResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabProgressionInstanceAPI::OnUnlinkLeaderboardFromStatisticResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FUnlinkLeaderboardFromStatisticDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    ProgressionModels::FEmptyResponse outResult;
    FPlayFabCppError errorResult;
    if (PlayFabRequestHandler::DecodeRequest(HttpRequest, HttpResponse, bSucceeded, outResult, errorResult))
    {
        SuccessDelegate.ExecuteIfBound(outResult);
    }
    else
    {
        ErrorDelegate.ExecuteIfBound(errorResult);
    }
}

bool UPlayFabProgressionInstanceAPI::UpdateLeaderboardEntries(
    ProgressionModels::FUpdateLeaderboardEntriesRequest& request,
    const FUpdateLeaderboardEntriesDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    TSharedPtr<UPlayFabAuthenticationContext> context = request.AuthenticationContext.IsValid() ? request.AuthenticationContext : GetOrCreateAuthenticationContext();
    if (context->GetEntityToken().Len() == 0) {
        UE_LOG(LogPlayFabCpp, Error, TEXT("You must call GetEntityToken API Method before calling this function."));
    }


    auto HttpRequest = PlayFabRequestHandler::SendRequest(this->settings, TEXT("/Leaderboard/UpdateLeaderboardEntries"), request.toJSONString(), TEXT("X-EntityToken"), context->GetEntityToken());
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabProgressionInstanceAPI::OnUpdateLeaderboardEntriesResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabProgressionInstanceAPI::OnUpdateLeaderboardEntriesResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FUpdateLeaderboardEntriesDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    ProgressionModels::FEmptyResponse outResult;
    FPlayFabCppError errorResult;
    if (PlayFabRequestHandler::DecodeRequest(HttpRequest, HttpResponse, bSucceeded, outResult, errorResult))
    {
        SuccessDelegate.ExecuteIfBound(outResult);
    }
    else
    {
        ErrorDelegate.ExecuteIfBound(errorResult);
    }
}

bool UPlayFabProgressionInstanceAPI::UpdateStatistics(
    ProgressionModels::FUpdateStatisticsRequest& request,
    const FUpdateStatisticsDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    TSharedPtr<UPlayFabAuthenticationContext> context = request.AuthenticationContext.IsValid() ? request.AuthenticationContext : GetOrCreateAuthenticationContext();
    if (context->GetEntityToken().Len() == 0) {
        UE_LOG(LogPlayFabCpp, Error, TEXT("You must call GetEntityToken API Method before calling this function."));
    }


    auto HttpRequest = PlayFabRequestHandler::SendRequest(this->settings, TEXT("/Statistic/UpdateStatistics"), request.toJSONString(), TEXT("X-EntityToken"), context->GetEntityToken());
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabProgressionInstanceAPI::OnUpdateStatisticsResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabProgressionInstanceAPI::OnUpdateStatisticsResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FUpdateStatisticsDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    ProgressionModels::FUpdateStatisticsResponse outResult;
    FPlayFabCppError errorResult;
    if (PlayFabRequestHandler::DecodeRequest(HttpRequest, HttpResponse, bSucceeded, outResult, errorResult))
    {
        SuccessDelegate.ExecuteIfBound(outResult);
    }
    else
    {
        ErrorDelegate.ExecuteIfBound(errorResult);
    }
}
